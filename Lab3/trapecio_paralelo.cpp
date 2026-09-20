#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <functional>
#include <cmath>
#include <chrono>

using namespace std;

// f(x) = 2x^2 + 3x + 0.5
double f(double x) {
    return 2 * x * x + 3 * x + 0.5;
}

// ---------- Pool de hilos sencillo ----------
// La idea es no estar creando y destruyendo hilos en cada calculo (eso cuesta
// caro), sino tener un grupo fijo de hilos esperando tareas en una cola.
class ThreadPool {
public:
    ThreadPool(size_t numHilos) : detener(false), tareasActivas(0) {
        for (size_t i = 0; i < numHilos; i++) {
            hilos.emplace_back([this]() { this->trabajador(); });
        }
    }

    ~ThreadPool() {
        {
            unique_lock<mutex> lock(mtx);
            detener = true;
        }
        cv.notify_all();
        for (thread &t : hilos) t.join();
    }

    void encolar(function<void()> tarea) {
        {
            unique_lock<mutex> lock(mtx);
            tareas.push(tarea);
            tareasActivas++;
        }
        cv.notify_one();
    }

    void esperarTodo() {
        unique_lock<mutex> lock(mtx);
        cvEspera.wait(lock, [this]() {
            return tareas.empty() && tareasActivas == 0;
        });
    }

private:
    void trabajador() {
        while (true) {
            function<void()> tarea;
            {
                unique_lock<mutex> lock(mtx);
                cv.wait(lock, [this]() {
                    return detener || !tareas.empty();
                });
                if (detener && tareas.empty()) return;
                tarea = tareas.front();
                tareas.pop();
            }
            tarea();
            {
                unique_lock<mutex> lock(mtx);
                tareasActivas--;
            }
            cvEspera.notify_all();
        }
    }

    vector<thread> hilos;
    queue<function<void()>> tareas;
    mutex mtx;
    condition_variable cv, cvEspera;
    bool detener;
    int tareasActivas;
};

// Calcula el area con n trapecios repartiendo el trabajo
// entre los hilos del pool.
// Aqui gestionamos memoria dinamica "a mano" con new/delete para guardar
// las sumas parciales de cada hilo.
double integrarConTrapecios(double a, double b, int n,
                             ThreadPool &pool, int numHilos) {
    double h = (b - a) / n;

    double *sumasParciales = new double[numHilos];
    for (int i = 0; i < numHilos; i++) sumasParciales[i] = 0.0;

    int puntosPorHilo = max(1, (n - 1) / numHilos);
    int desde = 1;

    for (int i = 0; i < numHilos && desde < n; i++) {
        int hasta = (i == numHilos - 1) ? n : min(n, desde + puntosPorHilo);
        int d = desde, hh = hasta, idx = i;

        pool.encolar([=]() {
            double suma = 0;
            for (int k = d; k < hh; k++) {
                suma += f(a + k * h);
            }
            sumasParciales[idx] = suma;
        });

        desde = hasta;
    }

    pool.esperarTodo();

    double sumaInterna = 0;
    for (int i = 0; i < numHilos; i++) sumaInterna += sumasParciales[i];

    delete[] sumasParciales; // liberamos la memoria que pedimos con new

    double suma = f(a) + f(b) + 2 * sumaInterna;
    return (h / 2) * suma;
}

int main() {
    double a = 2, b = 20;
    unsigned int numHilos = thread::hardware_concurrency();
    if (numHilos == 0) numHilos = 4;

    ThreadPool pool(numHilos);

    bool primera = true;
    double anterior = 0;
    double tolerancia = 1e-6;
    int n = 1;

    cout << "Calculando el area bajo f(x) = 2x^2 + 3x + 0.5" << endl;
    cout << "entre a=2 y b=20" << endl;
    cout << "Usando " << numHilos << " hilos en el pool" << endl << endl;

    auto inicio = chrono::high_resolution_clock::now();

    while (true) {
        double area = integrarConTrapecios(a, b, n, pool, numHilos);

        if (n <= 10 || n % 5000 == 0) {
            cout << "n = " << n << "   area = " << area << endl;
        }

        if (!primera && fabs(area - anterior) < tolerancia) {
            cout << endl << "El valor se estabilizo en n = " << n << endl;
            cout << "Area final aproximada: " << area << endl;
            break;
        }
        anterior = area;
        primera = false;
        n++;
    }

    auto fin = chrono::high_resolution_clock::now();
    cout << "Tiempo total: "
         << chrono::duration_cast<chrono::milliseconds>(fin - inicio).count()
         << " ms" << endl;

    return 0;
}
