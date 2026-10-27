#include <iostream>
using namespace std;

template <typename Tipo>
Tipo mayorDe(Tipo a, Tipo b) {
    return (a > b ? a : b);
}

int main() {
    char x = mayorDe<char>('e', 'z');
    int y = mayorDe<int>(9, 4);
    double z = mayorDe<double>(2.5, 7.25);
    cout << "caracter mayor: " << x << endl;
    cout << "numero mayor: " << y << endl;
    cout << "decimal mayor: " << z << endl;
    return 0;
}
