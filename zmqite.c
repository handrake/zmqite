#include <sqlite3ext.h>
#include <stdio.h>
#include "czmq.h"

SQLITE_EXTENSION_INIT1

static void zmqite_send(sqlite3_context *context, int argc, sqlite3_value **argv) {
    printf("hello, sqlite! arg: %s\n", sqlite3_value_text(argv[0]));
}

int sqlite3_zmqite_init(sqlite3 *db, char **pzErrMsg, const sqlite3_api_routines *pApi) {
    SQLITE_EXTENSION_INIT2(pApi);
    (void)pzErrMsg;
    return sqlite3_create_function(db, "zmqite_send", 1, SQLITE_UTF8 | SQLITE_INNOCUOUS, 0, zmqite_send, 0, 0);
}
