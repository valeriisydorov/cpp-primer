#ifndef INC_7_53_DEBUG_H
#define INC_7_53_DEBUG_H

class Debug
{
public:
    constexpr Debug(bool b = true): hw(b), io(b), other(b) {};
    constexpr Debug(bool h, bool i, bool o): hw(h), io(i), other(o) {};
    constexpr bool any() const
    {
        return hw || io || other;
    }
    void setHw(bool b) {
        hw = b;
    }
    void setIo(bool b) {
        io = b;
    }
    void setOther(bool b) {
        other = b;
    }
private:
    bool hw;
    bool io;
    bool other;
};

#endif
