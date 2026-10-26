# Act 2.5 - BST

Implementación de un árbol binario de búsqueda en C++ con templates.

## Archivos

- `TreeNode.h`: nodo del árbol.
- `BST.h`: estructura BST con inserción, eliminación, búsquedas, recorridos, altura, ancestros y niveles.
- `main.cpp`: menú para probar los métodos.

## Funciones

El programa permite insertar valores enteros, buscarlos, eliminarlos, consultar su nivel y sus ancestros, conocer la altura e imprimir los recorridos preorder, inorder, postorder y por niveles.

La clase `BST<T>` es genérica, aunque el menú de prueba trabaja con `int`. Los valores repetidos no se insertan. La altura se cuenta en niveles: árbol vacío = 0; árbol con solo la raíz = 1. La raíz está en el nivel 1.

## Compilar y ejecutar

Desde la carpeta de esta actividad:

```bash
clang++ -std=c++20 main.cpp -o BST
./BST
```

En CLion también se puede ejecutar con el target `Act25BST` agregado al `CMakeLists.txt` principal.

## Prueba rápida

Insertar: `8, 3, 10, 1, 6, 4, 7`.

- Inorder: `1 3 4 6 7 8 10`
- Preorder: `8 3 1 6 4 7 10`
- Postorder: `1 4 7 6 3 10 8`
- Por niveles: `8 3 10 1 6 4 7`
- Altura: `4`
- Ancestros de 4: `8 3 6`
- Nivel del 4: `4`
- Nivel de un valor inexistente: `-1`
