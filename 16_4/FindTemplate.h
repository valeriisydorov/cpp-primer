#ifndef FINDTEMPLATE_H
#define FINDTEMPLATE_H


template <typename I, typename T> I findTpl (I beg, I end, const T& val) {
    for (; beg != end; ++beg) {
        if (*beg == val) {
            return beg;
        }
    }
    return end;
}


#endif
