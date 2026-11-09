// ============================================================
//  CONTROLADOR
//  Es el "director de orquesta": recibe la opcion de la Vista,
//  le pide trabajo al Modelo y le dice a la Vista que mostrar.
//  Solo conoce a IVista (la interfaz), no a VistaConsola.
// ============================================================
#pragma once
#include <exception>
#include "GestorUsuarios.h"
#include "IVista.h"

class Controlador {
private:
    GestorUsuarios& modelo_;
    IVista&         vista_;

public:
    Controlador(GestorUsuarios& modelo, IVista& vista)
        : modelo_(modelo), vista_(vista) {}

    void ejecutar() {
        int opcion = -1;
        while (opcion != 0) {
            opcion = vista_.mostrarMenu();
            try {
                switch (opcion) {
                case 1: vista_.mostrarUsuarios(modelo_.listar()); break;
                case 2: agregar();  break;
                case 3: editar();   break;
                case 4: eliminar(); break;
                case 0: vista_.mostrarMensaje("Hasta luego!"); break;
                default: vista_.mostrarError("Opcion no valida.");
                }
            } catch (const std::exception& e) {
                // Las reglas del Modelo lanzan excepciones; el Controlador
                // las atrapa y la Vista las muestra.
                vista_.mostrarError(e.what());
            }
        }
    }

private:
    void agregar() {
        std::string nombre = vista_.pedirTexto("Nombre");
        std::string correo = vista_.pedirTexto("Correo");
        modelo_.agregar(nombre, correo);
        vista_.mostrarMensaje("Usuario agregado.");
    }

    void editar() {
        vista_.mostrarUsuarios(modelo_.listar());
        int id             = vista_.pedirEntero("ID a editar");
        std::string nombre = vista_.pedirTexto("Nuevo nombre");
        std::string correo = vista_.pedirTexto("Nuevo correo");
        modelo_.editar(id, nombre, correo);
        vista_.mostrarMensaje("Usuario actualizado.");
    }

    void eliminar() {
        vista_.mostrarUsuarios(modelo_.listar());
        int id = vista_.pedirEntero("ID a eliminar");
        modelo_.eliminar(id);
        vista_.mostrarMensaje("Usuario eliminado.");
    }
};
