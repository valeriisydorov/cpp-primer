#ifndef STRBLOB_H
#define STRBLOB_H

#include <initializer_list>
#include <string>
#include <vector>
#include <memory>

class StrBlobPtr;

class StrBlob {
    friend class StrBlobPtr;
    friend bool operator==(const StrBlob&, const StrBlob&);
    friend bool operator!=(const StrBlob&, const StrBlob&);
public:
    StrBlob();
    StrBlob(std::initializer_list<std::string> il);
    StrBlob(const StrBlob&);
    StrBlob& operator=(const StrBlob&);

    std::vector<std::string>::size_type size() const {
        return data->size();
    }
    bool empty() const {
        return data->empty();
    }
    void push_back(const std::string& s) const & {
        data->push_back(s);
    }
    void push_back(const std::string&& s) && {
        data->push_back(std::move(s));
    }
    void pop_back();
    std::string& front();
    const std::string& front() const;
    std::string& back();
    const std::string& back() const;

    StrBlobPtr begin();
    StrBlobPtr end();

private:
    std::shared_ptr<std::vector<std::string>> data;
    void check(std::vector<std::string>::size_type i, const std::string& msg) const;
};

#endif
