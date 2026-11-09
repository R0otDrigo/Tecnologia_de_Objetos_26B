from profesor import Profesor
from estudiante import Estudiante
from curso import Curso
from universidad import Universidad
from reporte import Reporte


def main():
    prof1 = Profesor("Carlos Vega", 45, "Base de Datos")
    prof2 = Profesor("Lucia Mendez", 39, "Programacion")

    est1 = Estudiante("Ana Torres", 20, "EST-001")
    est2 = Estudiante("Bruno Diaz", 21, "EST-002")
    est3 = Estudiante("Camila Rios", 19, "EST-003")

    print("=== PROFESORES ===")
    print(prof1)
    print(prof2)

    print("\n=== ESTUDIANTES ===")
    print(est1)
    print(est2)
    print(est3)

    curso1 = Curso("Tecnologia de Objetos", "Lunes", "08:00", "10:00")
    curso2 = Curso("Base de Datos II", "Miercoles", "14:00", "16:00")

    print("\n=== CURSOS ===")
    print(curso1)
    print(curso2)

    universidad = Universidad("Universidad Nacional de San Agustin")
    universidad.agregar_curso(curso1)
    universidad.agregar_curso(curso2)

    print("\n=== UNIVERSIDAD ===")
    print(universidad)
    for curso in universidad.get_cursos():
        print(f" -> {curso}")

    reporte = Reporte()
    texto_reporte = reporte.generar_reporte(est1)

    print("\n=== REPORTE GENERADO ===")
    print(texto_reporte)


if __name__ == "__main__":
    main()
