#include <iostream>
#include <string>

using namespace std;

template <typename T1, typename T2>
class Par {
private:
    T1 primero;
    T2 segundo;

public:
    Par(const T1& a, const T2& b) : primero(a), segundo(b) {}

    T1 getPrimero() const {
        return primero;
    }

    T2 getSegundo() const {
        return segundo;
    }

    void setPrimero(const T1& a) {
        primero = a;
    }

    void setSegundo(const T2& b) {
        segundo = b;
    }

    void mostrar() const {
        cout << "(" << primero << ", " << segundo << ")" << endl;
    }
};

int main() {
    Par<int, string> p1(10, "Arequipa");
    Par<double, char> p2(3.14, 'A');
    Par<string, bool> p3("activo", true);

    cout << "Par<int, string>: ";
    p1.mostrar();
    cout << "Par<double, char>: ";
    p2.mostrar();
    cout << "Par<string, bool>: ";
    p3.mostrar();

    p1.setPrimero(25);
    cout << "Despues de cambiar el primer valor: ";
    p1.mostrar();

    return 0;
}
