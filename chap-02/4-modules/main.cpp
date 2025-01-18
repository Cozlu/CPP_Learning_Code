#include "Rectangle.h"

#include <iostream>

int main()
{
    Rectangle rect(2.f, 4.f);
    std::cout << "{ L: " << rect.get_length() << ", W: " << rect.get_width() << " }" << std::endl;

    rect.scale(3);
    std::cout << "{ L: " << rect.get_length() << ", W: " << rect.get_width() << " }" << std::endl;

    Rectangle square(2.5f);

    // Rectangle::_default_size = 3.f;
    Rectangle::set_default_size(3.f);

    Rectangle s1;
    Rectangle s2;

    // Rectangle::_default_size = 5.f;
    Rectangle::set_default_size(5.f);

    Rectangle s3;
    Rectangle s4;
    Rectangle s5;

    std::cout << "s1 { L: " << s1.get_length() << ", W: " << s1.get_width() << " }" << std::endl;
    std::cout << "s2 { L: " << s2.get_length() << ", W: " << s2.get_width() << " }" << std::endl;
    std::cout << "s3 { L: " << s3.get_length() << ", W: " << s3.get_width() << " }" << std::endl;
    std::cout << "s4 { L: " << s4.get_length() << ", W: " << s4.get_width() << " }" << std::endl;
    std::cout << "s5 { L: " << s5.get_length() << ", W: " << s5.get_width() << " }" << std::endl;

    return 0;
}
