// ============================================================
//  MODELO (parte 1): la entidad Usuario
//  Guarda los datos de UNA persona. Atributos privados
//  (encapsulamiento) y acceso solo con getters/setters.
// ============================================================
#pragma once
#include <string>

class Usuario {
private:
    int         id_;
    std::string nombre_;
    std::string correo_;

public:
    Usuario(int id, const std::string& nombre, const std::string& correo)
        : id_(id), nombre_(nombre), correo_(correo) {}

    // Getters (solo lectura)
    int                getId()     const { return id_; }
    const std::string& getNombre() const { return nombre_; }
    const std::string& getCorreo() const { return correo_; }

    // Setters (modificacion controlada)
    void setNombre(const std::string& n) { nombre_ = n; }
    void setCorreo(const std::string& c) { correo_ = c; }
};
