#ifndef CONSTSTRBLOBPTR_H
#define CONSTSTRBLOBPTR_H

#include <string>
#include <vector>
#include <memory>

class StrBlob;

class ConstStrBlobPtr {
public:
    ConstStrBlobPtr(): curr(0) { }
    ConstStrBlobPtr(const StrBlob& a, size_t sz = 0);
    std::string& deref() const;
    ConstStrBlobPtr& incr();
    const std::string& operator*() const;
    const std::string* operator->() const;
private:
    std::shared_ptr<const std::vector<std::string>> check(size_t, const std::string&) const;
    std::weak_ptr<const std::vector<std::string>> wptr;
    size_t curr;
};

#endif
