#ifndef LISTTEMPLATE_H
#define LISTTEMPLATE_H


template <typename elemType> class ListItem;
template <typename elemType> class List {
public:
    List();
    List(const List<elemType>&);
    List<elemType>& operator=(const List<elemType>&);
    ~List();
    void insert(ListItem<elemType>* ptr, elemType value);
private:
    ListItem<elemType> *front, *back;
};



#endif
