public class Curso {
    private String nombre;
    private Horario horario;

    public Curso(String nombre, String dia, String horaInicio, String horaFin) {
        this.nombre = nombre;
        this.horario = new Horario(dia, horaInicio, horaFin);
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public Horario getHorario() {
        return horario;
    }

    public void setHorario(Horario horario) {
        this.horario = horario;
    }

    @Override
    public String toString() {
        return "Curso{nombre='" + nombre + "', horario=" + horario + "}";
    }
}
