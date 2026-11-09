package main

import (
	"fmt"
	"math"
	"runtime"
	"sync"
	"time"
)

// f(x) = 2x^2 + 3x + 0.5
func f(x float64) float64 {
	return 2*x*x + 3*x + 0.5
}

// tarea es el trabajo que le toca hacer a un worker: sumar f(x)
// para un rango de puntos internos [desde, hasta).
type tarea struct {
	desde, hasta int
}

// worker es el equivalente en Go a un "hilo del pool". En Go no se maneja
// el hilo del sistema operativo directamente como en Java o C++: se usan
// goroutines (livianas) y es el runtime de Go el que las reparte entre
// los hilos reales. Aun asi armamos un pool de goroutines fijo para que
// no se disparen miles de goroutines nuevas en cada calculo.
func worker(id int, a, h float64, tareas <-chan tarea,
	resultados chan<- float64, wg *sync.WaitGroup) {
	defer wg.Done()
	for t := range tareas {
		suma := 0.0
		for i := t.desde; i < t.hasta; i++ {
			suma += f(a + float64(i)*h)
		}
		resultados <- suma
	}
}

// integrarConTrapecios calcula el area aproximada con n trapecios,
// repartiendo el trabajo entre los goroutines del pool.
func integrarConTrapecios(a, b float64, n, numWorkers int) float64 {
	h := (b - a) / float64(n)

	tareas := make(chan tarea, numWorkers)
	resultados := make(chan float64, numWorkers)
	var wg sync.WaitGroup

	for w := 0; w < numWorkers; w++ {
		wg.Add(1)
		go worker(w, a, h, tareas, resultados, &wg)
	}

	puntosPorHilo := (n - 1) / numWorkers
	if puntosPorHilo < 1 {
		puntosPorHilo = 1
	}

	desde := 1
	numTareas := 0
	for i := 0; i < numWorkers && desde < n; i++ {
		hasta := desde + puntosPorHilo
		if i == numWorkers-1 || hasta > n {
			hasta = n
		}
		tareas <- tarea{desde, hasta}
		numTareas++
		desde = hasta
	}
	close(tareas)

	sumaInterna := 0.0
	for i := 0; i < numTareas; i++ {
		sumaInterna += <-resultados
	}

	wg.Wait()

	suma := f(a) + f(b) + 2*sumaInterna
	return (h / 2) * suma
}

func main() {
	a, b := 2.0, 20.0
	numWorkers := runtime.NumCPU()

	fmt.Println("Calculando el area bajo f(x) = 2x^2 + 3x + 0.5")
	fmt.Println("entre a=2 y b=20")
	fmt.Printf("Usando %d goroutines (pool) sobre %d CPUs\n\n",
		numWorkers, numWorkers)

	anterior := 0.0
	primera := true
	tolerancia := 1e-6
	n := 1

	inicio := time.Now()

	for {
		area := integrarConTrapecios(a, b, n, numWorkers)

		if n <= 10 || n%5000 == 0 {
			fmt.Printf("n = %-8d area = %.8f\n", n, area)
		}

		if !primera && math.Abs(area-anterior) < tolerancia {
			fmt.Printf("\nEl valor se estabilizo en n = %d\n", n)
			fmt.Printf("Area final aproximada: %.8f\n", area)
			break
		}
		anterior = area
		primera = false
		n++
	}

	fmt.Println("Tiempo total:", time.Since(inicio))
}
