#include <array>
#include <iostream>
#include <list>
#include <stack>
#include <string>
#include <vector>

enum Fruit
{
    Apricot,
    Cherry,
    Mango,
    Raspberry,

    Fruit_Count,
};

void try_arrays()
{
    std::array<std::string, Fruit_Count> fruits;
    fruits[Apricot]   = "apricot";
    fruits[Cherry]    = "cherry";
    fruits[Mango]     = "mango";
    fruits[Raspberry] = "raspberry";
}

void try_lists()
{
    std::list<int> l1;
    std::list<int> l2;
    std::list<int> l3;
    std::list<int> l4;

    l1.emplace_back(1);
    l2.emplace_back(2);
    l3.emplace_back(3);
    l4.emplace_back(4);

    l1.sort();
    l2.sort();
    l3.sort();
    l4.sort();
    l1.merge(l2);
    l3.merge(l4);
    auto mid = l3.begin();
    std::advance(mid, l3.size() / 2);
    l3.splice(mid, l1);
    for (auto n : l3)
    {
        std::cout << n << " ";
    }
    std::cout << std::endl;
}

void try_stacks()
{
    std::vector<int>                  v { 0, 1, 2 };
    std::stack<int, std::vector<int>> stack { v };
}

int main()
{

    try_arrays();
    try_lists();
    try_stacks();
    std::array<char, 3> lettres { 'a', 'b', 'c' };
    return 0;
}