#include <sqlite3ext.h>
#include <string.h>
#include <zmq.h>

SQLITE_EXTENSION_INIT1

static void zmqite_push(sqlite3_context *context, int argc, sqlite3_value **argv) {
    const char *endpoint = (const char *) sqlite3_value_text(argv[0]);
    const char *message = (const char *) sqlite3_value_text(argv[1]);
    size_t message_length = strlen(message);

    void *zmq_context = zmq_ctx_new();
    void *push = zmq_socket(zmq_context, ZMQ_PUSH);

    zmq_connect(push, endpoint);

    zmq_send(push, message, message_length, ZMQ_DONTWAIT);

    zmq_close(push);
    zmq_ctx_destroy(zmq_context);
}

int sqlite3_zmqite_init(sqlite3 *db, char **pzErrMsg, const sqlite3_api_routines *pApi) {
    SQLITE_EXTENSION_INIT2(pApi);
    (void)pzErrMsg;
    return sqlite3_create_function(db, "zmqite_push", 2, SQLITE_UTF8 | SQLITE_INNOCUOUS, 0, zmqite_push, 0, 0);
}
