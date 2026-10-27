#include <iostream>
#include <string>
using namespace std;

template <class T>
class Nodo {
public:
    T dato;
    Nodo<T>* siguiente;
    Nodo(T d) : dato(d), siguiente(nullptr) {}
};

template <class T>
class ListaEnlazada {
public:
    ListaEnlazada() : cabeza(nullptr), tamano(0) {}
    ~ListaEnlazada();
    void insertarInicio(T valor);
    void insertarFinal(T valor);
    void mostrar() const;
    int getTamano() const { return tamano; }
private:
    Nodo<T>* cabeza;
    int tamano;
};

template <class T>
ListaEnlazada<T>::~ListaEnlazada() {
    while (cabeza != nullptr) {
        Nodo<T>* temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
    }
}

template <class T>
void ListaEnlazada<T>::insertarInicio(T valor) {
    Nodo<T>* nuevo = new Nodo<T>(valor);
    nuevo->siguiente = cabeza;
    cabeza = nuevo;
    tamano++;
}

template <class T>
void ListaEnlazada<T>::insertarFinal(T valor) {
    Nodo<T>* nuevo = new Nodo<T>(valor);
    if (cabeza == nullptr) {
        cabeza = nuevo;
    } else {
        Nodo<T>* actual = cabeza;
        while (actual->siguiente != nullptr)
            actual = actual->siguiente;
        actual->siguiente = nuevo;
    }
    tamano++;
}

template <class T>
void ListaEnlazada<T>::mostrar() const {
    Nodo<T>* actual = cabeza;
    while (actual != nullptr) {
        cout << actual->dato << " -> ";
        actual = actual->siguiente;
    }
    cout << "NULL" << endl;
}

int main() {
    ListaEnlazada<int> edades;
    edades.insertarFinal(20);
    edades.insertarFinal(25);
    edades.insertarFinal(31);
    edades.insertarInicio(18);
    cout << "Secuencia de edades: ";
    edades.mostrar();
    cout << "Cantidad: " << edades.getTamano() << endl;

    ListaEnlazada<string> palabras;
    palabras.insertarFinal("Tecnologia");
    palabras.insertarFinal("de");
    palabras.insertarFinal("Objetos");
    palabras.insertarInicio("Curso:");
    cout << "Secuencia de palabras: ";
    palabras.mostrar();
    cout << "Cantidad: " << palabras.getTamano() << endl;
    return 0;
}
