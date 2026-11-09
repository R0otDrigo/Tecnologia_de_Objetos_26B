// ============================================================
//  MODELO (parte 2): GestorUsuarios
//  Contiene los datos y las REGLAS del negocio:
//  agregar, editar, eliminar, buscar y validar.
//  NO sabe nada de pantallas ni de cout/cin.
// ============================================================
#pragma once
#include <algorithm>
#include <stdexcept>
#include <string>
#include <vector>
#include "Usuario.h"

class GestorUsuarios {
private:
    std::vector<Usuario> usuarios_;
    int siguienteId_ = 1;

    // Regla: nombre no vacio y correo con '@' y sin repetir
    void validar(const std::string& nombre, const std::string& correo,
                 int idIgnorar = -1) const {
        if (nombre.empty())
            throw std::invalid_argument("El nombre no puede estar vacio.");
        if (correo.find('@') == std::string::npos)
            throw std::invalid_argument("El correo debe contener '@'.");
        for (const auto& u : usuarios_)
            if (u.getCorreo() == correo && u.getId() != idIgnorar)
                throw std::invalid_argument("Ese correo ya esta registrado.");
    }

    std::vector<Usuario>::iterator buscarIt(int id) {
        auto it = std::find_if(usuarios_.begin(), usuarios_.end(),
                               [id](const Usuario& u) { return u.getId() == id; });
        if (it == usuarios_.end())
            throw std::out_of_range("No existe un usuario con ese ID.");
        return it;
    }

public:
    void agregar(const std::string& nombre, const std::string& correo) {
        validar(nombre, correo);
        usuarios_.emplace_back(siguienteId_++, nombre, correo);
    }

    void editar(int id, const std::string& nombre, const std::string& correo) {
        auto it = buscarIt(id);
        validar(nombre, correo, id);
        it->setNombre(nombre);
        it->setCorreo(correo);
    }

    void eliminar(int id) {
        usuarios_.erase(buscarIt(id));
    }

    const std::vector<Usuario>& listar() const { return usuarios_; }
};
