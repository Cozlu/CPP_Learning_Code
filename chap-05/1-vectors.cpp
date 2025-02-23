#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    // std::vector<int> v { 4, 0 }; // constructeur 8
    std::vector<int> v(4, 0); // cette version affiche quatre "0" au lieu de "4 0".
    // constructeur 3
    for (auto n : v)
    {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    int              array[] = { 0, 1, 2, 3, 4, 5 };
    std::vector<int> v2(array, array + 6);
    for (auto n : v2)
    {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    auto size = v2.size();
    for (int l = 0, r = size - 1; l < r; ++l, --r)
    {
        std::swap(v2[l], v2[r]);
    }
    for (auto n : v2)
    {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    std::vector<int> v3 { 1, 2, 3 };
    for (auto it = v3.begin(); it != v3.end(); it += 2)
    {
        it = v3.insert(it, *it);
    }
    for (auto n : v3)
    {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    while (!v3.empty())
    {
        v3.pop_back();
    }
    for (auto n : v3)
    {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    std::vector<int> v4 { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    v4.erase(v4.begin() + 2, v4.begin() + 7);
    for (auto n : v4)
    {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    auto it = std::find(v4.begin(), v3.end(), 9);
    if (it != v4.end())
    {
        v4.erase(it);
    }
    for (auto n : v4)
    {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    v4.assign(5, 2);
    for (auto n : v4)
    {
        std::cout << n << " ";
    }
    std::cout << std::endl;
    v4.clear();
    for (auto n : v4)
    {
        std::cout << n << " ";
    }
    std::cout << std::endl;
    return 0;
}