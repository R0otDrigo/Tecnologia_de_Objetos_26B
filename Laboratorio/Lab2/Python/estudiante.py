from persona import Persona


class Estudiante(Persona):
    def __init__(self, nombre, edad, codigo):
        super().__init__(nombre, edad)
        self.__codigo = codigo

    def get_codigo(self):
        return self.__codigo

    def set_codigo(self, codigo):
        self.__codigo = codigo

    def __str__(self):
        return (f"Estudiante(nombre='{self.get_nombre()}', edad={self.get_edad()}, "
                f"codigo='{self.__codigo}')")
