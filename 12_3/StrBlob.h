#ifndef STRBLOB_H
#define STRBLOB_H

#include <initializer_list>
#include <string>
#include <vector>
#include <memory>

class StrBlob {
public:
    StrBlob();
    StrBlob(std::initializer_list<std::string> il);

    std::vector<std::string>::size_type size() const {
        return data->size();
    }
    bool empty() const {
        return data->empty();
    }
    void push_back(const std::string &s)
    {
        data->push_back(s);
    }
    void push_back(const std::string &s) const
    {
        data->push_back(s);
    }
    void pop_back();
    void pop_back() const;
    std::string& front();
    const std::string& front() const;
    std::string& back();
    const std::string& back() const;
private:
    std::shared_ptr<std::vector<std::string>> data;
    void check(std::vector<std::string>::size_type i, const std::string& msg) const;
};

#endif
