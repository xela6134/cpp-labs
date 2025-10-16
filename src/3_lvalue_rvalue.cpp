#include <iostream>

template <typename T>
void f(T&& param) {
    std::cout << __PRETTY_FUNCTION__ << ", " << param << '\n';
}

void f1(int x) {
    std::cout << x << '\n';
}

// can only take temporaries, e.g. f(10)
void f2(int&& x) {
    std::cout << x << '\n';
}

int main() {
    // lvalue: Something that has a name or address (you can take its address with &)
    // rvalue: A temporary value, doesnt have a name

    int a = 5;   // x is an lvalue
    f1(a);        // x = lvalue
    f1(10);       // 10 = rvalue (temporary)

    // Normally && means rvalue reference (can only bind to rvalues)
    f2(3);
    // f2(x); -> invalid

    // BUT: T&& behaves differently in templates
    // 'universal reference' (aka forwarding reference)
    // Now f() can take both lvalues and rvalues
    int x = 5;
    const int cx = x;
    const int& rx = x;

    f(x);   // lvalue
    f(cx);  // const lvalue
    f(rx);  // const lvalue reference
    f(27);  // rvalue
}
