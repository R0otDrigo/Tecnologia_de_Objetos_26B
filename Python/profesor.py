from persona import Persona


class Profesor(Persona):
    def __init__(self, nombre, edad, especialidad):
        super().__init__(nombre, edad)
        self.__especialidad = especialidad

    def get_especialidad(self):
        return self.__especialidad

    def set_especialidad(self, especialidad):
        self.__especialidad = especialidad

    def __str__(self):
        return (f"Profesor(nombre='{self.get_nombre()}', edad={self.get_edad()}, "
                f"especialidad='{self.__especialidad}')")
