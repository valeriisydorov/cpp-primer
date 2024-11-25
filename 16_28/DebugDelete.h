#ifndef DEBUGDELETE_H
#define DEBUGDELETE_H


#include <iostream>


class DebugDelete {
public:
    /**
     *
     * @param s
     */
    DebugDelete(std::ostream& s = std::cerr): os(s) { }

    /**
     *
     * @tparam T
     * @param p
     */
    template<typename T> void operator() (T* p) const {
        os << "deleting UniquePtr" << std::endl;
        delete p;
    }
private:
    std::ostream& os;
};


#endif
