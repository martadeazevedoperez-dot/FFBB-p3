#include "utils.h"

int no_deleted_registers = NO_DELETED_REGISTERS;

void replaceExtensionByIdx(const char * fileName, char * indexName){
    int i;

    strcpy(indexName, fileName);

    for ( i = 0; indexName[i] != '\0'; i++)
    {
        if (indexName[i] == '.')
        {
            indexName[i]='\0';
            break;
        }
    }

    trcat(indexName, ".idx");
}

bool createTable(const char * tableName) {
    FILE *f;
    int deleted = -1;
    char indexname[INDEX_NAME_SIZE];

    /*abre fichero datos*/
    f=fopen(tableName, "rb");

    /*si no, lo crea, con cabezera -1 que indica que está vacio*/
    if(!f) {
        f=fopen(tableName, "wb");
        if (!f)
            return false;

        if (fwrite(&deleted, sizeof(int), 1, f) != 1) {
            fclose(f);
            return false;
        }
        fclose(f);
    }
    else
        fclose(f);

    /*aqui crea nombre fichero indice*/
    replaceExtensionByIdx(tableName, indexname);

    /*si es necesario crea el indice*/
    if (!createIndex(indexname))
    {
        return false;
    }

    return true;
}

bool createIndex(const char *indexName) {
    FILE *f;
    int header[2];

    if(!indexName){
	    return false;
    }

    f = fopen(indexName, "rb");
    if(f){
	    fclose(f);
	    return true,
    }

    f = fopen(indexName, "wb");
    if(!f){
	    return false;
    }

    header[0] = NO_DELETED_REGISTERS;
    header[1] = NO_DELETED_REGISTERS;
    
    if(fwrite(header, sizeof(int), 2, f) != 2){
	    fclose(f);
	    return false;
    }

    if(fclose(f) != 0){
	    return false;
    }


    return true;
}

void printnode(size_t _level, size_t level, FILE * indexFileHandler, int node_id, char side) {


    return;
}

void printTree(size_t level, const char * indexName)
{
    FILE *f;
    int root;
    int deleted;

    f=fopen(indexName, "rb");
    if (!f)
        return;
        
    /*obtiene del indice la cabecera*/
    if(fread(&root, sizeof(int), 1, f) != 1){
        fclose(f);
        return;
    }
    if(fread(&deleted, sizeof(int), 1, f) != 1){
        fclose(f);
        return;
    }

    /*si esta vacio no imprime nada*/
    if (root == -1)
    {
        fclose(f);
        return;
    }
    else /*sino imprime nodos*/
    {
        printnode(0 , level, f, root, NULL);
        fclose(f);
    }
    
}

bool findKey(const char * book_id, const char *indexName,
             int * nodeIDOrDataOffset)
 {
     return true;
 }

bool addIndexEntry(char * book_id,  int bookOffset, char const * indexName) {
    return true;
}

bool addTableEntry(Book * book, const char * dataName,
                   const char * indexName) {
    return true;
}
