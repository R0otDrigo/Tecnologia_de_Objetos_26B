class Universidad:
    def __init__(self, nombre):
        self.__nombre = nombre
        self.__cursos = []

    def get_nombre(self):
        return self.__nombre

    def set_nombre(self, nombre):
        self.__nombre = nombre

    def get_cursos(self):
        return self.__cursos

    def agregar_curso(self, curso):
        self.__cursos.append(curso)

    def __str__(self):
        return f"Universidad(nombre='{self.__nombre}', totalCursos={len(self.__cursos)})"
