#include "Controlador.h"
#include "GestorUsuarios.h"
#include "VistaConsola.h"

int main() {
  GestorUsuarios modelo;
  VistaConsola vista;
  Controlador controlador(modelo, vista);

  modelo.agregar("Ana Torres", "ana@correo.com") modelo
      .agregar("Luis Perez", "luis@correo.com")

          controlador.ejecutar();

  return 0;
}
