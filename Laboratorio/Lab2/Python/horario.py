class Horario:
    def __init__(self, dia, hora_inicio, hora_fin):
        self.__dia = dia
        self.__hora_inicio = hora_inicio
        self.__hora_fin = hora_fin

    def get_dia(self):
        return self.__dia

    def set_dia(self, dia):
        self.__dia = dia

    def get_hora_inicio(self):
        return self.__hora_inicio

    def set_hora_inicio(self, hora_inicio):
        self.__hora_inicio = hora_inicio

    def get_hora_fin(self):
        return self.__hora_fin

    def set_hora_fin(self, hora_fin):
        self.__hora_fin = hora_fin

    def __str__(self):
        return f"Horario(dia='{self.__dia}', de={self.__hora_inicio} a {self.__hora_fin})"
