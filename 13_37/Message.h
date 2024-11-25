#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
#include <set>

class Folder;

class Message {
    friend void swap(Message&, Message&);
    friend class Folder;
public:
    explicit Message(const std::string& str = ""): contents(str) {}
    Message(const Message&);
    Message& operator=(const Message&);
    ~Message();
    void save(Folder&);
    void remove(Folder&);
private:
    std::string contents;
    std::set<Folder*> folders;
    void addToFolders(const Message&);
    void removeFromFolders();
    void addFolder(Folder*);
    void remFolder(Folder*);
};


#endif
