#include <iostream>
#include <fstream>
#include <string>


int main()
{
    std::fstream inOut("../copyOut", std::fstream::ate | std::fstream::in | std::fstream::out);

    if (!inOut)
    {
        std::cerr << "Unable to open file!" << std::endl;

        return EXIT_FAILURE;
    }

    std::fstream::pos_type endMark = inOut.tellg();

    inOut.seekg(0, std::fstream::beg);
    std::size_t cnt = 0;
    std::string line;
    while (inOut && inOut.tellg() != endMark && getline(inOut, line))
    {
        cnt += line.size() + 1;

        std::fstream::pos_type currMark = inOut.tellg();
        inOut.seekp(0, std::fstream::end);

        inOut << cnt;

        if (currMark != endMark)
        {
            inOut << " ";
        }

        inOut.seekg(currMark);
    }

    inOut.seekp(0, std::fstream::end);

    inOut << "\n";

    return 0;
}