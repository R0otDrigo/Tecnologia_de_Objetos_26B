// ============================================================
//  VISTA (parte 2): VistaConsola  (hereda de IVista)
//  SOLO muestra informacion y lee lo que escribe la persona.
//  No valida reglas ni guarda datos.
// ============================================================
#pragma once
#include <iomanip>
#include <iostream>
#include <limits>
#include "IVista.h"

class VistaConsola : public IVista {
public:
    int mostrarMenu() override {
        std::cout << "\n===== GESTION DE USUARIOS (MVC) =====\n"
                  << " 1. Listar usuarios\n"
                  << " 2. Agregar usuario\n"
                  << " 3. Editar usuario\n"
                  << " 4. Eliminar usuario\n"
                  << " 0. Salir\n";
        return pedirEntero("Elige una opcion");
    }

    void mostrarUsuarios(const std::vector<Usuario>& lista) override {
        if (lista.empty()) {
            std::cout << "\n(No hay usuarios registrados)\n";
            return;
        }
        std::cout << "\n" << std::left
                  << std::setw(5)  << "ID"
                  << std::setw(20) << "NOMBRE"
                  << "CORREO\n"
                  << std::string(50, '-') << "\n";
        for (const auto& u : lista)
            std::cout << std::setw(5)  << u.getId()
                      << std::setw(20) << u.getNombre()
                      << u.getCorreo() << "\n";
    }

    std::string pedirTexto(const std::string& pregunta) override {
        std::cout << pregunta << ": ";
        std::string s;
        std::getline(std::cin >> std::ws, s);
        return s;
    }

    int pedirEntero(const std::string& pregunta) override {
        std::cout << pregunta << ": ";
        int n;
        if (!(std::cin >> n)) {            // entrada invalida o fin de datos
            if (std::cin.eof()) return 0;  // fin de entrada -> salir
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return -1;                     // opcion no valida
        }
        return n;
    }

    void mostrarMensaje(const std::string& texto) override {
        std::cout << "[OK] " << texto << "\n";
    }

    void mostrarError(const std::string& texto) override {
        std::cout << "[ERROR] " << texto << "\n";
    }
};
