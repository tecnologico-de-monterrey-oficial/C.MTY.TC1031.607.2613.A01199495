## ¿En qué casos notaste que la versión recursiva fue más lenta o usó más memoria que la iterativa? ¿A qué se debió?
En todas las recursivas fue más lenta que la iterativa, esto se debe a que utiliza mucha más memoria para almacenar todas las recursiones en vez de un for o un while que es solo 1;
## Para la suma 1..n, sumFormula resuelve en un solo paso lo que a sumIterative y sumRecursive les toma n pasos. ¿Qué te dice esto sobre buscar una fórmula antes de escribir código?
Que a veces una solución más simple y sencilla con investigar puedes hacer que algo sea mucho más rápido de compilar y ejecutar, que no la solución más complicada es la mejor.
## Si bacteriasRecursive tuviera que calcular n = 100,000 días, ¿qué problema esperarías encontrar y cómo lo resolverías?
Pues más que nada problemas de memoria, serían demasiado como para almacenar toda esa info entonces a lo mejor habría un overflow o un data leak y crashearía el programa o me daría un dato equivocado por el data leak.