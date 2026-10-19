# Evidencia 2 - Estructuras de Datos Lineales
**Alumno:** Diego Villanueva Fernandez  
**Matricula:** A01199495  
**Materia:** TC1031 - Estructuras de Datos
## Descripcion
Programa  para leer y analizar registros de eventos de red. Usa estructuras de datos que implemente en la Parte A.
La **fila (Queue)** recibe las lineas del archivo en orden de llegada. Despues se validan y se guardan en una **lista doblemente ligada (DoublyLinkedList)**. Para ordenar los registros por fecha y hora use **Merge Sort**, reorganizando los nodos sin pasar los registros a un arreglo. La **pila (Stack)** sirve para mostrar los eventos de un dia en orden descendente.
## Como compilar y ejecutar
Se puede abrir el repositorio en CLion y ejecutar la configuracion **Evidence2**. Tambien se puede compilar desde la carpeta raiz del repositorio:
```bash
cmake -S . -B cmake-build-debug
cmake --build cmake-build-debug --target Evidence2 TestStructures
```
Para ejecutar desde la raiz del repositorio (importante por las rutas de los archivos):
```bash
./cmake-build-debug/Evidence2
```
Para correr las pruebas de las estructuras de la Parte A:
```bash
./cmake-build-debug/TestStructures
```
En CLion, configurar **Working directory** como `$ProjectFileDir$`.
## Archivos de entrada
Los archivos principales estan en `Evidences/Evidence2/data/`:
- `log607-1.txt`
- `log607-2.txt`
El programa permite elegir uno de ellos o escribir una ruta diferente. El formato de cada linea es:
```text
Mmm DD AAAA HH:MM:SS IP Descripcion del evento
```
Ejemplo:
```text
Sep 29 2024 14:37:38 10.14.19.188 Unauthorized Access Attempts
```
Elmes debe estar abreviado en ingles (`Jan`, `Feb`, `Mar`, etc.), el dia debe tener dos digitos, el anio cuatro digitos y la hora debe estar en formato de 24 horas. El programa revisa las fechas, horas e IP y reporta el numero y motivo de cada linea invalida sin detenerse. El archivo `logs_prueba.txt` contiene ejemplos validos e invalidos para comprobar esto.
## Opciones del programa
1. **Ordenar por fecha y hora:** usa Merge Sort estable, pide una prediccion del crecimiento de comparaciones y muestra tiempo, comparaciones, profundidad maxima de recursion y resultado. Guarda `Evidences/Evidence2/out/output608.out`.
2. **Buscar logs por dia:** recibe una fecha como `Sep 14 2024` y muestra los registros encontrados. Se necesita elegir primero la opcion 1.
3. **Mostrar logs en orden descendente:** usa una pila para invertir los registros del ultimo dia buscado. Si todavia no se ha buscado, pide una fecha.
4. **Estadisticas:** muestra el total de registros, dia con mas incidentes, evento mas frecuente e IP mas repetida. Incluye todos los empates.
5. **Salir:** termina el programa.
## Pruebas y resultados
`TestStructures` comprueba estructuras vacias, un elemento, inserciones y eliminaciones en extremos, orden LIFO/FIFO y recorrido en ambas direcciones. Tambien probe archivo inexistente, registros invalidos, fecha invalida, dia sin registros, busqueda antes de ordenar y lista ya ordenada.
Resultados de ejemplo de mis ejecuciones (el tiempo puede variar entre corridas):
| Archivo | Registros | Prediccion | Tiempo | Comparaciones | Profundidad | Orden correcto |
|---|---:|---|---:|---:|---:|---|
| `log607-1.txt` | 6818 | n log n | 2.915 ms | 78330 | 14 | Si |
| `log607-2.txt` | 6818 | n log n | 1.911 ms | 50624 | 14 | Si |
Merge Sort es estable: cuando dos registros tienen exactamente la misma fecha y hora, se mantiene su orden de llegada. El segundo archivo necesito menos comparaciones porque venia casi ordenado.
Las capturas, los casos de prueba y la explicacion completa estan en `docs/Evidencia2.pdf`.
## Uso de IA

Use ChatGPT como apoyo para adaptar mis estructuras anteriores, revisar errores de compilacion y sugerir partes de la lectura, el ordenamiento y las validaciones. Probe el programa en CLion y revise los resultados con ambos archivos. No use estructuras `std::list`, `std::stack` ni `std::queue` para sustituir las implementaciones propias. En el documento de evidencia explico las sugerencias de la IA, mis cambios y un error detectado y corregido, solamente lo use parala creacion del README para que me apoyara a que todo se viera bonito pero era la unica cosa que no ocupaba codigo o reflexion yo le pase toda la info y solo me lo dejo en un formato bonito .

## Video explicativo

**https://drive.google.com/file/d/1BKiiDMbIJdvyQQi5a4FfC8lff7olXXkF/view?usp=sharing:**