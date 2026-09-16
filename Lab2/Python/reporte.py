class Reporte:
    def generar_reporte(self, estudiante):
        return (
            "----- REPORTE TEMPORAL -----\n"
            f"Nombre: {estudiante.get_nombre()}\n"
            f"Edad: {estudiante.get_edad()}\n"
            f"Codigo: {estudiante.get_codigo()}\n"
            "-----------------------------"
        )
