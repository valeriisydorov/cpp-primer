#ifndef NUMBERED2_H
#define NUMBERED2_H

class Numbered2 {
public:
    Numbered2() {
        static int cnt = 0;
        mysn = cnt++;
    }
    Numbered2(const Numbered2& orig) {
        static int cnt = 0;
        mysn = cnt++;
    }
    int mysn;
};

#endif
