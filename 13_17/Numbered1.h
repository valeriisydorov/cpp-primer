#ifndef NUMBERED1_H
#define NUMBERED1_H


class Numbered1 {
public:
    Numbered1() {
        static int cnt = 0;
        mysn = cnt++;
    }
    int mysn;
};


#endif
