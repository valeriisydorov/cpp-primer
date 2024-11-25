#ifndef FOLDER_H
#define FOLDER_H

#include <set>

class Message;

class Folder {
    friend void swap(Message&, Message&);
    friend class Message;
public:
    Folder()=default;
    Folder(const Folder&);
    Folder& operator=(const Folder&);
    ~Folder();
    void save(Message&);
    void remove(Message&);
private:
    std::set<Message*> msgs;
    void addToMessages(const Folder&);
    void removeFromMessages();
    void addMsg(Message*);
    void remMsg(Message*);
};

#endif
