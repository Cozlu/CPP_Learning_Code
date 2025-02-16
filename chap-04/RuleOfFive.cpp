#include <iostream>
#include <vector>

class RuleOfFive
{
public:
    std::vector<int>* vect_ptr;
    RuleOfFive(int i, int j)
        : vect_ptr { new std::vector<int> {} }
    {
        vect_ptr->emplace_back(i);
        vect_ptr->emplace_back(j);
    }
    ~RuleOfFive() { delete vect_ptr; }

    RuleOfFive(const RuleOfFive& other)
        : vect_ptr { new std::vector<int> { *(other.vect_ptr) } }
    {}
    RuleOfFive(RuleOfFive&& other)
        : vect_ptr { new std::vector<int> { std::move(*(other.vect_ptr)) } }
    {}
    RuleOfFive& operator=(const RuleOfFive& other)
    {
        if (this != &other)
        {
            (*vect_ptr) = *(other.vect_ptr);
        }

        return *this;
    }
    RuleOfFive& operator=(RuleOfFive&& other)
    {
        if (this != &other)
        {
            (*vect_ptr) = std::move(*(other.vect_ptr));
        }
        return *this;
    }
};

// This function should pass by reference, but we make a copy on purpose
void affiche(RuleOfFive s)
{
    for (auto& i : *(s.vect_ptr))
        std::cout << i << " ";
    std::cout << std::endl;
}

int main()
{
    RuleOfFive r { 1, 2 };
    affiche(r); // 1 2

    RuleOfFive t { 9000, 9001 };
    r = t;
    t.vect_ptr->clear();
    affiche(r); // 9000 9001

    RuleOfFive u = std::move(r);
    affiche(u); // 9000 9001
    affiche(r); // (an empty line)

    r = std::move(u);
    affiche(u); // (an empty line)
    affiche(r); // 9000 9001
}