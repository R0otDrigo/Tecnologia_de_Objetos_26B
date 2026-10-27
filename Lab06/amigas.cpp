#include <iostream>
using namespace std;

template <class T>
class Caja {
    T valor;
public:
    Caja(T v) : valor(v) {}
    // amiga plantilla: cada Caja<T> hace amiga a su propia operator<<
    friend ostream& operator<<(ostream& os, const Caja<T>& c) {
        return os << "Caja(" << c.valor << ")";
    }
    // amiga no plantilla: solo para Caja<int>
    friend void reiniciar(Caja<int>& c);
};

void reiniciar(Caja<int>& c) { c.valor = 0; }

int main() {
    Caja<int> a(7);
    Caja<string> b("hola");
    cout << a << " " << b << endl;
    reiniciar(a);
    cout << a << endl;
    return 0;
}
