#include <iostream>
using namespace std;

template <typename T>
class Contenedor {
public:
    T metodo1(int xx) {
        return array[xx];
    }
    void metodo2(T val, int i) {
        array[i] = val;
    }
    void mostrar() const;
private:
    T array[4];
};

template <typename T>
void Contenedor<T>::mostrar() const {
    for (int i = 0; i < 4; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main() {
    Contenedor<int> z;
    z.metodo2(10, 0);
    z.metodo2(50, 1);
    z.metodo2(60, 2);
    z.metodo2(70, 3);
    z.mostrar();
    cout << "posicion 2: " << z.metodo1(2) << endl;

    Contenedor<double> w;
    w.metodo2(1.5, 0);
    w.metodo2(2.5, 1);
    w.metodo2(3.5, 2);
    w.metodo2(4.5, 3);
    w.mostrar();
    return 0;
}
