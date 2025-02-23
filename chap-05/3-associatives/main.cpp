#include "keys.h"

#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

int main()
{
    std::set<ComparableDog> s1;
    ComparableDog           medor { "medor", "labrador" };
    s1.emplace(medor);
    ComparableDog gus { "gus", "bordercollie" };
    s1.emplace(gus);
    std::cout << s1.size() << std::endl;
    auto medor2 { medor };
    s1.emplace(medor2);
    std::cout << s1.size() << std::endl;

    std::unordered_set<HashableDog> s2;
    HashableDog                     m3 { "medor", "labrador" };
    s2.emplace(m3);

    using Owner = std::pair<std::string, std::string>;
    std::map<ComparableDog, Owner> m;
    m.insert({ medor, { "A", "AA" } });
    m.emplace(gus, Owner { "B", "BB" });
    m.insert_or_assign(gus, Owner { "C", "CC" });
    m.try_emplace(medor, "D", "DD");
    return 0;
}