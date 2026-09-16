public class Estudiante extends Persona {
    private String codigo;

    public Estudiante(String nombre, int edad, String codigo) {
        super(nombre, edad);
        this.codigo = codigo;
    }

    public String getCodigo() {
        return codigo;
    }

    public void setCodigo(String codigo) {
        this.codigo = codigo;
    }

    @Override
    public String toString() {
        return "Estudiante{nombre='" + getNombre() + "', edad=" + getEdad()
                + ", codigo='" + codigo + "'}";
    }
}
