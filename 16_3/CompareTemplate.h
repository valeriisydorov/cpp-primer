#ifndef COMPARETEMPLATE_H
#define COMPARETEMPLATE_H


template <typename T> int compare(const T& v1, const T& v2) {
    if (v1 < v2) {
        return -1;
    } else if (v2 < v1) {
        return 1;
    } else {
        return 0;
    }
}


#endif
