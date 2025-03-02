#include <iostream>
#include <string>

class BoxedString
{
    std::string _str;

public:
    BoxedString(std::string str)
        : _str { std::move(str) }
    {}
};

int main()
{
    std::string some_str { "Hello world!" };
    BoxedString b1 { some_str };
    BoxedString b2 { std::move(some_str) };
    BoxedString b3 { std::string { "Hello Universe!" } };
    BoxedString b4 { "Hello Universe!" };
}