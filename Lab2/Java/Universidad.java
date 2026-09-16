import java.util.ArrayList;
import java.util.List;
 
public class Universidad {
    private String nombre;
    // Agregación: la Universidad "tiene" cursos, pero los cursos
    // se crean afuera (en el Main) y solo se agregan aqui con un metodo.
    // Si la universidad desaparece, los cursos podrian seguir existiendo.
    private List<Curso> cursos;
 
    public Universidad(String nombre) {
        this.nombre = nombre;
        this.cursos = new ArrayList<>();
    }
 
    public String getNombre() {
        return nombre;
    }
 
    public void setNombre(String nombre) {
        this.nombre = nombre;
    }
 
    public List<Curso> getCursos() {
        return cursos;
    }
 
    public void agregarCurso(Curso curso) {
        this.cursos.add(curso);
    }
 
    @Override
    public String toString() {
        return "Universidad{nombre='" + nombre + "', totalCursos=" + cursos.size() + "}";
    }
}
