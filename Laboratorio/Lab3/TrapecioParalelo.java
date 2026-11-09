import java.util.concurrent.*;
import java.util.ArrayList;
import java.util.List;

public class TrapecioParalelo {

    // Esta es la funcion que nos toco integrar: f(x) = 2x^2 + 3x + 0.5
    static double f(double x) {
        return 2 * x * x + 3 * x + 0.5;
    }

    // Esta clase representa el "pedacito" de trabajo que le toca a cada hilo.
    // Cada hilo suma f(x) solo para el rango de puntos que le asignamos.
    static class TareaParcial implements Callable<Double> {
        private final double a, h;
        private final int desde, hasta;

        TareaParcial(double a, double h, int desde, int hasta) {
            this.a = a;
            this.h = h;
            this.desde = desde;
            this.hasta = hasta;
        }

        @Override
        public Double call() {
            double sumaParcial = 0;
            for (int i = desde; i < hasta; i++) {
                sumaParcial += f(a + i * h);
            }
            return sumaParcial;
        }
    }

    // Calcula el area aproximada con n trapecios, repartiendo el trabajo
    // entre los hilos del pool.
    static double integrarConTrapecios(double a, double b, int n,
                                        ExecutorService pool, int numHilos) throws Exception {
        double h = (b - a) / n;

        List<Future<Double>> futuros = new ArrayList<>();
        int puntosPorHilo = Math.max(1, (n - 1) / numHilos);

        int desde = 1;
        for (int i = 0; i < numHilos && desde < n; i++) {
            int hasta = (i == numHilos - 1) ? n
                    : Math.min(n, desde + puntosPorHilo);
            futuros.add(pool.submit(new TareaParcial(a, h, desde, hasta)));
            desde = hasta;
        }

        double sumaInterna = 0;
        for (Future<Double> fu : futuros) {
            sumaInterna += fu.get();
        }

        double suma = f(a) + f(b) + 2 * sumaInterna;
        return (h / 2) * suma;
    }

    public static void main(String[] args) throws Exception {
        double a = 2, b = 20;
        int numHilos = Runtime.getRuntime().availableProcessors();

        // Pool de threads: en vez de crear y destruir un hilo por cada calculo,
        // dejamos un grupo fijo de hilos ya listos y les vamos mandando tareas.
        ExecutorService pool = Executors.newFixedThreadPool(numHilos);

        double anterior = Double.NaN;
        double tolerancia = 1e-6;
        int n = 1;

        System.out.println("Calculando el area bajo f(x) = 2x^2 + 3x + 0.5");
        System.out.println("entre a=2 y b=20");
        System.out.println("Usando " + numHilos + " hilos en el pool\n");

        long inicio = System.currentTimeMillis();

        while (true) {
            double area = integrarConTrapecios(a, b, n, pool, numHilos);

            if (n <= 10 || n % 5000 == 0) {
                System.out.printf("n = %-8d area = %.8f%n", n, area);
            }

            boolean seEstabilizo = !Double.isNaN(anterior)
                    && Math.abs(area - anterior) < tolerancia;
            if (seEstabilizo) {
                System.out.println("\nEl valor se estabilizo en n = " + n);
                System.out.printf("Area final aproximada: %.8f%n", area);
                break;
            }
            anterior = area;
            n++;
        }

        long fin = System.currentTimeMillis();
        System.out.println("Tiempo total: " + (fin - inicio) + " ms");

        pool.shutdown();
    }
}
