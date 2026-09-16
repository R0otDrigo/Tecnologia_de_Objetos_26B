from horario import Horario


class Curso:
    def __init__(self, nombre, dia, hora_inicio, hora_fin):
        self.__nombre = nombre
        self.__horario = Horario(dia, hora_inicio, hora_fin)

    def get_nombre(self):
        return self.__nombre

    def set_nombre(self, nombre):
        self.__nombre = nombre

    def get_horario(self):
        return self.__horario

    def set_horario(self, horario):
        self.__horario = horario

    def __str__(self):
        return f"Curso(nombre='{self.__nombre}', horario={self.__horario})"
