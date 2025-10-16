#include <iostream>

// A forwarding function is a function template that:
// Takes arguments as universal references (T&&)
// Passes them (forwards them) to another function without changing whether they were lvalues or rvalues

void g(int& x)  { 
    std::cout << "lvalue\n"; 
}

void g(int&& x) { 
    std::cout << "rvalue\n"; 
}

template <typename T>
void f0(T x) {              // copies or decays everything
    g(x);                   // always calls lvalue version
}

template <typename T>
void f1(T&& t) {            // universal reference
    g(std::forward<T>(t));  // perfectly forwarded
}

struct Widget {
    Widget(int& x)  { 
        std::cout << "lvalue constructor\n"; 
    }
    
    Widget(int&& x) { 
        std::cout << "rvalue constructor\n"; 
    }
};

template <typename T>
Widget make_widget(T&& arg) {
    return Widget(std::forward<T>(arg));  // forward arg to Widget's constructor
}

int main() {
    int x = 5;
    f0(x);
    f0(10);
    f1(x);
    f1(10);

    std::cout << '\n';

    int a = 5;
    make_widget(a);   // lvalue
    make_widget(5);   // rvalue
}
