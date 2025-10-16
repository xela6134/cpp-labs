#include <iostream>

// no need to do
// -> decltype(t + u)
// after c++14
template <typename T, typename U>
auto add(T t, U u) -> decltype(t + u) {
    return t + u;
}

int main() {
    // decltype(f()) sum = x;
    // Here, the compiler does not call f
    // It uses the type that such a call woudl return as the type for sum
    // The compiler gives sum the same type as the type that would be returned if we were to call f

    int x = 5;
    int& ref = x;

    decltype(x) a;          // int
    decltype(ref) b = x;    // int&

    int x1 = 5;
    double x2 = 2.3;
    auto result = add(x1, x2);      // decltype(a + b) → double
    std::cout << result << '\n';    // prints 7.3
}
