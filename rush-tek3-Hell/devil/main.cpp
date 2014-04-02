#include "Inspector.hpp"

struct test {};
struct lol {};
std::ostream& operator<<(std::ostream& out, const lol&)
{
    out << "Lol instance given";
    return out;
}

int main(int, char**)
{
    test t;
    lol l;
    std::string str = "salut";
    inspect(t);
    inspect(str);
    inspect(l);

    return 0;
}
