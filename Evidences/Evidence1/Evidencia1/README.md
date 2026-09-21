# Evidencia 1 - Ordenamiento y búsqueda de logs

**Alumno:** Diego Villanueva Fernández  
**Matrícula:** A01199495  
**Grupo:** 607

## Instrucciones para compilar y ejecutar

El proyecto fue desarrollado en C++ utilizando CLion y CMake.

Para ejecutarlo en CLion:

1. Abrir el proyecto.
2. Compilar el proyecto con CMake.
3. Ejecutar `evidencia1.cpp`.
4. Seleccionar uno de los archivos disponibles:
    - `log607-1.txt`
    - `log607-2.txt`
5. Seleccionar uno de los algoritmos de ordenamiento.
6. Ingresar la predicción solicitada por el programa.
7. Después del ordenamiento, ingresar el rango de fechas que se desea buscar.

Los archivos `log607-1.txt` y `log607-2.txt` deben permanecer dentro de la carpeta de la evidencia.

El programa genera:

- `output607.txt`: contiene los registros ordenados cronológicamente.
- `range607.txt`: contiene los registros encontrados dentro del rango solicitado.

## Formato de fechas esperado

Las fechas deben ingresarse con el siguiente formato:

```text
Sep 29 2024 14:37:38
```

Formato general:

```text
Mes Día Año HH:MM:SS
```

Ejemplo:

```text
Start date and time: Oct 02 2024 23:04:24
End date and time: Oct 02 2024 23:04:24
```

Los límites del rango son inclusivos.

Si existen varios registros con exactamente el mismo timestamp en alguno de los límites, el programa incluye todos los registros que tengan ese timestamp.

Si la fecha ingresada tiene un formato incorrecto, el programa la rechaza y solicita nuevamente la entrada.

## Política de uso de Inteligencia Artificial

La Inteligencia Artificial se utilizó como herramienta de apoyo durante el desarrollo de la evidencia.

### Uso permitido

Se utilizó IA para:

- Explicar conceptos de algoritmos de ordenamiento y búsqueda.
- Resolver dudas sobre complejidad temporal.
- Revisar partes del código y ayudar a detectar errores.
- Sugerir casos de prueba.
- Analizar los tiempos obtenidos durante las pruebas.
- Revisar la implementación de la búsqueda por rango y el manejo de timestamps duplicados.
- Hacer Bonito el README.md

Todas las sugerencias fueron revisadas antes de integrarlas al proyecto y se modificaron cuando fue necesario.

Un ejemplo concreto fue Bubble Sort. Inicialmente se consideró que podía tener un mejor caso `O(n)`, pero al revisar mi implementación observé que no utiliza una condición de parada anticipada. Por esta razón, mi implementación realiza los ciclos completos y su mejor caso se reportó como `O(n^2)`.

### Uso no permitido

La IA no se utilizó para sustituir mi comprensión del programa ni para entregar código sin revisarlo.

No se aceptaron automáticamente las respuestas generadas por IA. El código fue probado, modificado y revisado durante el desarrollo, y las decisiones finales se tomaron con base en el funcionamiento real del programa.

## Video explicativo

**Enlace al video:**  
[Ver video de la Evidencia 1](https://drive.google.com/file/d/1sD5IzkpSjOAyQv1chYX76JFAMGgnOXI_/view?usp=sharing)
