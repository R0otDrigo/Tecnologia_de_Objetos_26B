#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;

mutex mtxCout;

void imprimirPares() {
    for (int i = 2; i <= 20; i += 2) {
        {
            lock_guard<mutex> lock(mtxCout);
            cout << "Par: " << i << endl;
        }
        this_thread::sleep_for(chrono::milliseconds(50));
    }
}

void imprimirImpares() {
    for (int i = 1; i <= 20; i += 2) {
        {
            lock_guard<mutex> lock(mtxCout);
            cout << "Impar: " << i << endl;
        }
        this_thread::sleep_for(chrono::milliseconds(50));
    }
}

int main() {
    thread hiloPares(imprimirPares);
    thread hiloImpares(imprimirImpares);

    hiloPares.join();
    hiloImpares.join();

    return 0;
}
