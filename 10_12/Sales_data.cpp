#include "Sales_data.h"

bool compareIsbn(Sales_data& trans1, Sales_data& trans2) {
    return trans1.bookNo < trans2.bookNo;
}