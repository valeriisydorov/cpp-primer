#include "Sales_data.h"

bool compareIsbn(const Sales_data& trans1, const Sales_data& trans2) {
    return trans1.bookNo < trans2.bookNo;
}