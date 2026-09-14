public class Reporte {
    // Dependencia: Reporte NO guarda al Estudiante como atributo,
    // solo lo recibe como parametro del metodo cuando lo necesita.
    // Por eso es una dependencia y no una asociacion o composicion.
 
    public String generarReporte(Estudiante estudiante) {
        return "----- REPORTE TEMPORAL -----\n" +
               "Nombre: " + estudiante.getNombre() + "\n" +
               "Edad: " + estudiante.getEdad() + "\n" +
               "Codigo: " + estudiante.getCodigo() + "\n" +
               "-----------------------------";
    }
}
