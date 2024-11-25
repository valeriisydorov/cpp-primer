#include "QueryResult.h"


std::set<std::vector<std::string>::size_type>::const_iterator QueryResult::begin() const {
    return lines->cbegin();
}

std::set<std::vector<std::string>::size_type>::const_iterator QueryResult::end() const {
    return lines->cend();
}

std::shared_ptr<std::vector<std::string>> QueryResult::getFile() {
    return file;
}

std::ostream& print(std::ostream& os, const QueryResult& qr) {
    os << qr.sought << " occurs " << qr.lines->size() << " " << "time(s)" << std::endl;
    for (std::vector<std::string>::size_type num: *qr.lines) {
        os << "\t(line " << num + 1 << ") " << *(qr.file->begin() + num) << std::endl;
    }
    return os;
}