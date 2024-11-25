#include "Connection.h"

#include<memory>

void f(destionation &d) {
    connection c = connect(&d);
    std::shared_ptr<connection> p(&c, [](connection* p) -> void {
        disconnect(*p);
    });
}