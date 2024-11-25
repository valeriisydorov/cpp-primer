#include "Message.h"
#include "Folder.h"

Folder::Folder(const Folder& f): msgs(f.msgs) {
    addToMessages(f);
}

Folder& Folder::operator=(const Folder& f) {
    removeFromMessages();
    msgs = f.msgs;
    addToMessages(f);
    return *this;
}

Folder::~Folder() {
    removeFromMessages();
}

void Folder::addMsg(Message* m) {
    msgs.insert(m);
}

void Folder::remMsg(Message* m) {
    msgs.erase(m);
}

void Folder::save(Message& m)
{
    msgs.insert(&m);
    m.addFolder(this);
}

void Folder::remove(Message& m) {
    msgs.erase(&m);
    m.remFolder(this);
}

void Folder::addToMessages(const Folder& f) {
    for (auto msg : f.msgs) {
        msg->addFolder(this);
    }
}

void Folder::removeFromMessages() {
    for (auto msg : msgs) {
        msg->remFolder(this);
    }
}

