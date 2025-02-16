#include <iostream>
#include <string>

class Person
{
public:
    Person(const std::string& name, const std::string& surname)
        : _name { name }
        , _surname { surname }
    {}

    Person(const Person& other)
        : _name { other._name }
        , _surname { other._surname }
    {}

    Person& operator=(const Person& other)
    {
        if (this != &other)
        {
            _name    = other._name;
            _surname = other._surname;
        }
        return *this;
    }

    Person& operator=(Person&& other)
    {
        if (this != &other)
        {
            _name    = std::move(other._name);
            _surname = std::move(other._surname);
        }

        return *this;
    }

    void wait(unsigned int years) { _age += years; }

    friend std::ostream& operator<<(std::ostream& o, const Person& p)
    {
        std::cout << "A person named \"" << p._name << " " << p._surname << "\" with age " << p._age << ".";
        return o;
    }

private:
    std::string  _name;
    std::string  _surname;
    unsigned int _age = 0u;
};

int main()
{
    Person batman { "Bruce", "Wayne" };
    batman.wait(23);
    std::cout << batman << std::endl;

    // partie Copie
    Person clone { batman };
    std::cout << clone << std::endl;

    // partie Affectation
    Person assigned_clone { "Batman", "2" };
    std::cout << assigned_clone << std::endl;

    assigned_clone = batman;
    std::cout << assigned_clone << std::endl;

    Person assigned_clone2 { "Batman", "2" };
    std::cout << assigned_clone << std::endl;

    assigned_clone2 = std::move(batman);
    std::cout << batman << std::endl;

    return 0;
}