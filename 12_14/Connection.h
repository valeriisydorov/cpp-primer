#ifndef CONNECTION_H
#define CONNECTION_H

struct destionation;
struct connection;

connection connect(destionation*);
void disconnect(connection);

void end_connection(connection* p);
void f(destionation &d);

#endif
