import java.util.List;

public class Main {
    public static void main(String[] args) {
        Profesor prof1 = new Profesor("Carlos Vega", 45, "Base de Datos");
        Profesor prof2 = new Profesor("Lucia Mendez", 39, "Programacion");

        Estudiante est1 = new Estudiante("Ana Torres", 20, "EST-001");
        Estudiante est2 = new Estudiante("Bruno Diaz", 21, "EST-002");
        Estudiante est3 = new Estudiante("Camila Rios", 19, "EST-003");

        System.out.println("=== PROFESORES ===");
        System.out.println(prof1);
        System.out.println(prof2);

        System.out.println("\n=== ESTUDIANTES ===");
        System.out.println(est1);
        System.out.println(est2);
        System.out.println(est3);

        Curso curso1 = new Curso("Tecnologia de Objetos", "Lunes", "08:00", "10:00");
        Curso curso2 = new Curso("Base de Datos II", "Miercoles", "14:00", "16:00");

        System.out.println("\n=== CURSOS ===");
        System.out.println(curso1);
        System.out.println(curso2);

        Universidad universidad = new Universidad("Universidad Nacional de San Agustin");
        universidad.agregarCurso(curso1);
        universidad.agregarCurso(curso2);

        System.out.println("\n=== UNIVERSIDAD ===");
        System.out.println(universidad);
        List<Curso> listaCursos = universidad.getCursos();
        for (Curso curso : listaCursos) {
            System.out.println(" -> " + curso);
        }

        Reporte reporte = new Reporte();
        String textoReporte = reporte.generarReporte(est1);

        System.out.println("\n=== REPORTE GENERADO ===");
        System.out.println(textoReporte);
    }
}
