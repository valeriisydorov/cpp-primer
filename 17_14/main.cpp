#include <iostream>
#include <regex>


using std::regex;


int main()
{
    try
    {
        regex regexErrorCType("[[:abc:]]");
        regex regexErrorEscape("\\");
        regex regexErrorBackRef("\\1");
        regex regexErrorBrack("[abc");
        regex regexErrorParen("([a-zA-Z]+");
        regex regexErrorBrace("a{2,");
        regex regexErrorBadBrade("a{5,3}");
        regex regexErrorRange("[z-a]");
        regex regexErrorBadRepeat("*abc");
    }
    catch (const std::regex_error& err)
    {
        std::cout << err.what() << "\ncode: " << err.code() << std::endl;
    }

    return 0;
}
