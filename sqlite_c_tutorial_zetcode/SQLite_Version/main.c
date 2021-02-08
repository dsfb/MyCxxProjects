#include <stdio.h>
#include <stdlib.h>

#include "sqlite3.h"

int main()
{
    printf("The SQLite 3 available version is: %s\n", sqlite3_libversion());

    return 0;
}
