#pragma once


#include <initializer_list>
#include <string>
#include <vector>
#include <memory>


class StrBlobPtr;

class StrBlob
{
    friend class StrBlobPtr;

public:
    StrBlob();
    StrBlob(std::initializer_list<std::string> il);

    std::vector<std::string>::size_type size() const
    {
        return data->size();
    }
    bool empty() const
    {
        return data->empty();
    }
    void push_back(const std::string &s)
    {
        data->push_back(s);
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