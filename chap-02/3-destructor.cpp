#include <iostream>
#include <string>

class Person
{
public:
    Person(std::string name, std::string surname)
        : _name { name }
        , _surname { surname }
    {}
    ~Person() { std::cout << get_full_name() << " died at " << get_age() << " years old" << std::endl; }

    std::string  get_full_name() const { return _name + " " + _surname; }
    unsigned int get_age() const { return _age; }

    void wait(unsigned int years) { _age += years; }

private:
    std::string  _name;
    std::string  _surname;
    unsigned int _age = 0u;
};

class Batmobile
{
public:
    ~Batmobile() { std::cout << "The Batmobile has been destroyed" << std::endl; }

private:
    Person _batman { "Bruce", "Wayne" };
};

int main()
{
    /*
    {
        Person batman { "Bruce", "Wayne" };
        batman.wait(23);
    }

    std::cout << "After block" << std::endl;
    */
    {
        Batmobile batmobile;
    }

    std::cout << "After block" << std::endl;
    return 0;
}