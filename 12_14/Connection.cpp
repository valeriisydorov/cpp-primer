#include "Connection.h"

#include<memory>

void end_connection(connection* p) {
    disconnect(*p);
}

void f(destionation &d) {
    connection c = connect(&d);
    std::shared_ptr<connection> p(&c, end_connection);
}