#include <iostream>
using namespace std;

template <typename T> T suma(T a, T b)  { return a + b; }
template <typename T> T resta(T a, T b) { return a - b; }
template <typename T> T producto(T a, T b) { return a * b; }
template <typename T> T division(T a, T b) { return a / b; }

int main() {
    cout << "int:    " << suma<int>(10, 45) << " " << resta<int>(10, 45)
         << " " << producto<int>(10, 45) << " " << division<int>(45, 10) << endl;
    cout << "double: " << suma<double>(3.45, 8.10) << " " << resta<double>(3.45, 8.10)
         << " " << producto<double>(3.45, 8.10) << " " << division<double>(8.10, 3.45) << endl;
    return 0;
}
