#include <stdio.h>
#include <stdlib.h>

#include "sqlite3.h"

int main()
{
    sqlite3 *db;
    char *err_msg = 0;
    sqlite3_stmt *res;

    int rc = sqlite3_open("test.db", &db);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);

        return 1;
    }

    char *sql = "SELECT Id, Name FROM Cars WHERE Id = ?";

    rc = sqlite3_prepare_v2(db, sql, -1, &res, 0);

    if (rc == SQLITE_OK) {
        sqlite3_bind_int(res, 1, 3);
    } else {
        fprintf(stderr, "Failed to execute Select statement: %s\n", sqlite3_errmsg(db));
    }

    int step = sqlite3_step(res);

    if (step == SQLITE_ROW) {
        printf("Id = %s: ", sqlite3_column_text(res, 0));
        printf("Name = %s\n", sqlite3_column_text(res, 1));
    }

    sqlite3_finalize(res);
    sqlite3_close(db);

    return 0;
}
