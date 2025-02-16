#include <iostream>

class RuleOfThree
{
public:
    int* int_ptr;
    RuleOfThree(int i) { int_ptr = new int { i }; }
    ~RuleOfThree() { delete int_ptr; }

    RuleOfThree(const RuleOfThree& other) { int_ptr = new int { *(other.int_ptr) }; }
    RuleOfThree& operator=(const RuleOfThree& other)
    {
        if (this != &other)
        {
            *int_ptr = *(other.int_ptr);
        }

        return *this;
    }
};

void f(RuleOfThree s)
{
    std::cout << *(s.int_ptr) << std::endl;
    // s is destroyed at the end of the function f
}

int main()
{
    RuleOfThree r { 42 };

    f(r); // Calling f copies r
          // the copy is destroyed at the end of the call
    std::cout << *(r.int_ptr) << std::endl;

    RuleOfThree t { 9001 };
    r            = t;
    *(t.int_ptr) = 0;
    std::cout << *(r.int_ptr) << std::endl; // devrait afficher 9001
    std::cout << *(t.int_ptr) << std::endl; // devrait afficher 0
    return 0;
}