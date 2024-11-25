#include "Folder.h"
#include "Message.h"

Message::Message(const Message& m): contents(m.contents), folders(m.folders) {
    addToFolders(m);
}

Message& Message::operator=(const Message& rhs) {
    removeFromFolders();
    contents = rhs.contents;
    folders = rhs.folders;
    addToFolders(rhs);
    return *this;
}

Message::~Message() {
    removeFromFolders();
}

void swap(Message& lhs, Message& rhs) {
    using::swap;
    for (auto f: lhs.folders) {
        f->remMsg(&lhs);
    }
    for (auto f: rhs.folders) {
        f->remMsg(&rhs);
    }
    swap(lhs.folders, rhs.folders);
    swap(lhs.contents, rhs.contents);
    for (auto f: lhs.folders) {
        f->addMsg(&lhs);
    }
    for (auto f: rhs.folders) {
        f->addMsg(&rhs);
    }
}

void Message::save(Folder& f) {
    folders.insert(&f);
    f.addMsg(this);
}

void Message::remove(Folder& f) {
    folders.erase(&f);
    f.remMsg(this);
}

void Message::addToFolders(const Message& m) {
    for (auto f: m.folders) {
        f->addMsg(this);
    }
}

void Message::removeFromFolders() {
    for (auto f: folders) {
        f->remMsg(this);
    }
}

void Message::addFolder(Folder* f) {
    folders.insert(f);
}

void Message::remFolder(Folder* f) {
    folders.erase(f);
}
