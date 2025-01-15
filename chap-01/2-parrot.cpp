#include <iostream>
#include <sstream>
#include <string>
#include <vector>

/* 4.
int main()
{
    std::string line;
    auto        array = std::vector<std::string> {};
    while (true)
    {

        std::getline(std::cin, line);
        if (line.empty())
        {
            break;
        }
        array.emplace_back(line);
    }
    for (auto repeat : array)
    {
        std::cout << "Craow " << repeat << std::endl;
    }

    return 0;
}*/

int main()
{
    std::string       line;
    std::stringstream builder;
    while (true)
    {
        std::getline(std::cin, line);
        if (line.empty())
        {
            break;
        }
        builder << "Craow " << line << std::endl;
    }
    std::cout << builder.str();

    std::stringstream b;
    b << 3 << "petits" << true << std::endl;
    std::cout << b.str();
    return 0;
}