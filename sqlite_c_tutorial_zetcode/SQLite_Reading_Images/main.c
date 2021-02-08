#include <stdio.h>
#include <stdlib.h>

#include "sqlite3.h"

int main()
{
    FILE *fp = fopen("woman2.jpg", "wb");

    if (fp == NULL) {
        fprintf(stderr, "Cannot open image file for writing\n");

        return 1;
    }

    sqlite3 *db;
    char *err_msg = 0;

    int rc = sqlite3_open("test.db", &db);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);

        return 1;
    }

    char *sql = "SELECT Data FROM Images WHERE Id = 1";

    sqlite3_stmt *pStmt;
    rc = sqlite3_prepare_v2(db, sql, -1, &pStmt, 0);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Failed to prepare statement\n");
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));

        sqlite3_close(db);

        return 1;
    }

    rc = sqlite3_step(pStmt);

    int bytes = 0;

    if (rc == SQLITE_ROW) {
        bytes = sqlite3_column_bytes(pStmt, 0);
    }

    fwrite(sqlite3_column_blob(pStmt, 0), bytes, 1, fp);

    if (ferror(fp)) {
        fprintf(stderr, "fwrite() failed\n");

        return 1;
    }

    int r = fclose(fp);

    if (r == EOF) {
        fprintf(stderr, "Cannot close file handler\n");
    }

    rc = sqlite3_finalize(pStmt);

    sqlite3_close(db);

    return 0;
}
