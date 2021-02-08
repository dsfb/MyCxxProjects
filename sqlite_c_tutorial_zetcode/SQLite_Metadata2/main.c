#include <stdio.h>
#include <stdlib.h>

#include "sqlite3.h"

int callback(void *, int, char **, char **);

int main()
{
    sqlite3 *db;
    char *err_msg = 0;

    int rc = sqlite3_open("test.db", &db);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);

        return 1;
    }

    char *sql = "SELECT name FROM sqlite_master WHERE type='table'";

    rc = sqlite3_exec(db, sql, callback, 0, &err_msg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Failed to select data from table info!\n");
        fprintf(stderr, "SQL Table Info error: %s\n", err_msg);

        sqlite3_free(err_msg);
        sqlite3_close(db);

        return 1;
    }

    sqlite3_close(db);

    return 0;
}

int callback(void *NotUsed, int argc, char **argv, char **azColName) {
    NotUsed = 0;

    for (int i = 0; i < argc; i++) {
        printf("Table name: %s\n", argv[i] ? argv[i] : "NULL");
    }

    return 0;
}
