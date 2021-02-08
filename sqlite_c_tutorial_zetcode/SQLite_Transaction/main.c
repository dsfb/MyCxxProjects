#include <stdio.h>
#include <stdlib.h>

#include "sqlite3.h"

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

    char *sql = "DROP TABLE IF EXISTS Friends;"
                "BEGIN TRANSACTION;"
                "CREATE TABLE Friends(Id INTEGER PRIMARY KEY, Name TEXT);"
                "INSERT INTO Friends(Name) VALUES ('Tom');"
                "INSERT INTO Friends(Name) VALUES ('Rebecca');"
                "INSERT INTO Friends(Name) VALUES ('Jim');"
                "INSERT INTO Friend(Name) VALUES ('Robert');"
                "COMMIT;";

    rc = sqlite3_exec(db, sql, 0, 0, &err_msg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL Error: %s\n", err_msg);

        sqlite3_free(err_msg);
        sqlite3_close(db);

        return 1;
    }

    sqlite3_close(db);

    return 0;
}
