#include <iostream>
#include <string>
#include <tuple>

std::tuple<bool, int, int> parse_params(int argc, const char* const* argv)
{
    const std::tuple<bool, int, int> error { false, 0, 0 };

    if (argc != 3)
    {
        std::cerr << "Program expects 2 parameters!" << std::endl;
        return error;
    }

    std::string num_str = argv[1];
    std::string den_str = argv[2];

    int numerator   = 0;
    int denominator = 0;

    try
    {
        numerator   = std::stoi(num_str);
        denominator = std::stoi(den_str);
    }
    catch (const std::exception&)
    {
        std::cerr << "Program expects 2 integer parameters!" << std::endl;
        return error;
    }

    if (denominator == 0)
    {
        std::cerr << "Denominator cannot be null!" << std::endl;
        return error;
    }

    return { true, numerator, denominator };
}

std::tuple<int, int> divide(int numerator, int denominator)
{
    return { numerator / denominator, numerator % denominator };
}

int main(int argc, char** argv)
{
    const auto parse = parse_params(argc, argv);

    if (!std::get<0>(parse))
    {
        return 1;
    }

    const auto numerator   = std::get<1>(parse);
    const auto denominator = std::get<2>(parse);
    const auto tuple_res   = divide(numerator, denominator);

    std::cout << numerator << " = " << denominator << " * " << std::get<0>(tuple_res) << " + "
              << std::get<1>(tuple_res) << std::endl;

    return 0;
}