//
// Created by Diego Villanueva Fernandez on 18/08/26.
// Matricula: A01199495
//

#ifndef C_MTY_TC1031_607_2613_A01199495_ACT12RECURSION_H
#define C_MTY_TC1031_607_2613_A01199495_ACT12RECURSION_H


 class Act12Recursion {

public:
    static int sumIterative(int n) {
        int x=0;
        for (int i = 1; i<= n; i++) {
            x += i;

        }
        return x;
    };

    static int sumRecursive(int n) {
        if (n <= 1){ return 1;}
        return n + sumRecursive(n-1);
    };

     static int sumFormula(int n) {
         return (n*(n+1))/2;
     }

     static int fibonacciIterative(int n) {
         if (n == 1) {
             return 1;
         }
         if (n == 2) {
             return 1;
         }

         int prev = 1;
         int curr = 1;
         int next = 0;

         for (int i = 3; i <= n; i++) {
             next = prev + curr;
             prev = curr;
             curr = next;
         }

         return curr;
     }
     static int fibonacciRecursive(int n) {
         if (n == 1 || n == 2) {
             return 1;
         }
         return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
     }

     static int bacteriasIterative(int n) {
         int bacterias = 1;
         int newbacterias = 0;
         int deadbacterias = 0;

         for (int i = 1; i <= n; i++) {
             newbacterias =   bacterias * 3.78;
             deadbacterias = bacterias * 2.34;
             bacterias = bacterias + newbacterias - deadbacterias;
         }
         return bacterias;
     }

     static int bacteriasRecursive(int n) {
         if (n == 0){return 1;}
         int bacterias = bacteriasRecursive(n-1);
         int newbacterias =   bacterias * 3.78;
         int deadbacterias = bacterias * 2.34;
         return bacterias + newbacterias - deadbacterias;
     }

     static int investmentIterative(int cantidad, int meses) {
         for (int i = 1; i <= meses; i++) {
             int nuevacantidad =  cantidad * 1.1875;
             cantidad = nuevacantidad;
         }
            return cantidad;
     }

     static int investmentRecursive(int cantidad, int meses) {
         if (meses == 0) { return cantidad; }
         int nuevacantidad = cantidad * 1.1875;
         cantidad = investmentRecursive(nuevacantidad, meses - 1);
         return cantidad;
     }

     static int powIterative(int n, int y) {
         int resultado = 1;
         for (int i = 1; i <= y; i++) {
             resultado = resultado * n;
         }
         return resultado;
     }

     static int powRecursive(int n, int y) {
         if (y == 0) { return 1; }
         return n * powRecursive(n, y - 1);
     }
     
};


#endif //C_MTY_TC1031_607_2613_A01199495_ACT12RECURSION_H
