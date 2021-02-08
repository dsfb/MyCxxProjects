#include <stdio.h>
#include <stdlib.h>

#include "sqlite3.h"

int main()
{
    FILE *fp = fopen("woman.jpg", "rb");

    if (fp == NULL) {
        fprintf(stderr, "Cannot open image file\n");

        return 1;
    }

    fseek(fp, 0, SEEK_END);

    if (ferror(fp)) {
        fprintf(stderr, "fseek() failed on file \'woman.jpg\'\n");
        int r = fclose(fp);

        if (r == EOF) {
            fprintf(stderr, "Cannot close file \'woman.jpg\' handler\n");
        }

        return 1;
    }

    int flen = ftell(fp);

    if (flen == -1) {
        perror("error occurred");
        int r = fclose(fp);

        if (r = EOF) {
            fprintf(stderr, "Cannot close file \'woman.jpg\' handler\n");
        }

        return 1;
    }

    fseek(fp, 0, SEEK_SET);

    if (ferror(fp)) {
        fprintf(stderr, "fseek() failed on file \'woman.jpg\'\n");
        int r = fclose(fp);

        if (r == EOF) {
            fprintf(stderr, "Cannot close file handler");
        }

        return 1;
    }

    char data[flen + 1];

    int size = fread(data, 1, flen, fp);

    if (ferror(fp)) {
        fprintf(stderr, "fread() failed on file \'woman.jpg\'\n");
        int r = fclose(fp);

        if (r == EOF) {
            fprintf(stderr, "Cannot close file \'woman.jpg\' handler\n");
        }

        return 1;
    }

    int r = fclose(fp);

    if (r == EOF) {
        fprintf(stderr, "Cannot close file \'woman.jpg\' handler\n");
    }

    sqlite3 *db;
    char *err_msg = 0;

    int rc = sqlite3_open("test.db", &db);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);

        return 1;
    }

    sqlite3_stmt *pStmt;

    char *sql = "INSERT INTO Images(Data) VALUES(?);";

    rc = sqlite3_prepare(db, sql, -1, &pStmt, 0);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot prepare Insert statement: %s\n", sqlite3_errmsg(db));

        return 1;
    }

    sqlite3_bind_blob(pStmt, 1, data, size, SQLITE_STATIC);

    rc = sqlite3_step(pStmt);

    if (rc != SQLITE_DONE) {
        printf("execution Insertion failed: %s\n", sqlite3_errmsg(db));
    }

    sqlite3_finalize(pStmt);

    sqlite3_close(db);

    return 0;
}
