#include "QueryResult.h"

std::ostream& print(std::ostream& os, const QueryResult& qr) {
    os << qr.sought << " occurs " << qr.lines->size() << " " << "time(s)" << std::endl;
    StrBlobPtr temp(qr.file);
    for (std::vector<std::string>::size_type num: *qr.lines) {
        for (int i = 0; i != num; ++i) {
            temp.incr();
        }
        os << "\t(line " << num + 1 << ") " << temp.deref() << std::endl;
    }
    return os;
}