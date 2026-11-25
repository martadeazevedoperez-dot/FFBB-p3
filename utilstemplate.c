#include "utils.h"

int no_deleted_registers = NO_DELETED_REGISTERS;

void replaceExtensionByIdx(const char *fileName, char * indexName) {
    return;
}


bool createTable(const char * tableName) {
    FILE *f;
    int deleted = -1, i;
    char indexname[INDEX_HEADER_SIZE];

    /*abre fichero datos*/
    f=fopen(tableName, "r");

    /*si no, lo crea, con cabezera -1 que indica que está vacio*/
    if(!f) {
        f=fopen(tableName, "w");
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
    strcpy(indexname, tableName);

    for ( i = 0; indexname[i] != '\0'; i++)
    {
        if (indexname[i] == '.')
        {
            indexname[i]='\0';
            break;
        }
    }

    strcat(indexname, ".idx");

    /*si es necesario crea el indice*/
    if (!createIndex(indexname))
    {
        return false;
    }

    return true;
}

bool createIndex(const char *indexName) {

    return true;
}
void printnode(size_t _level, size_t level,
               FILE * indexFileHandler, int node_id, char side) {
    return;
}

void printTree(size_t level, const char * indexName)
{
    return;
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