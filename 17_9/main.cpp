#include <iostream>
#include <string>
#include <bitset>


using std::string;
using std::bitset;


int main()
{
    bitset<64> bitvec(32);
    std::cout << "bitset<64> bitvec(32) " << bitvec << std::endl;

    bitset<32> bv(1010101);
    std::cout << "bitset<32> bv(1010101) " << bv << std::endl;

    string bstr;
    std::cin >> bstr;
    bitset<8>bs(bstr);
    std::cout << "bitset<8>bs(bstr) " << bs << std::endl;

    return 0;
}
