// ============================================================
//  VISTA (parte 1): interfaz abstracta IVista
//  Define QUE debe poder hacer cualquier vista, no COMO.
//  Gracias a esto se puede cambiar la consola por Qt, web, etc.
//  sin tocar el Modelo ni el Controlador (polimorfismo).
// ============================================================
#pragma once
#include <string>
#include <vector>
#include "Usuario.h"

class IVista {
public:
    virtual ~IVista() = default;

    virtual int         mostrarMenu() = 0;                       // devuelve la opcion elegida
    virtual void        mostrarUsuarios(const std::vector<Usuario>& lista) = 0;
    virtual std::string pedirTexto(const std::string& pregunta) = 0;
    virtual int         pedirEntero(const std::string& pregunta) = 0;
    virtual void        mostrarMensaje(const std::string& texto) = 0;
    virtual void        mostrarError(const std::string& texto) = 0;
};
