#include <iostream>
#include <vector>
#include <string>

namespace first {
    int x = 1;
    namespace one {
        int x = 3;
    }
}

typedef std::vector<std::pair<std::string, int>> pairlist_t;

namespace second {
    int x = 2;
}

int main() {
    using namespace first::one;

    pairlist_t a;

    std::cout << first::x << ", " << first::one::x << ", " << second::x << ", " << x << "\n"; 
}
