#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FILAS 5
#define COLUMNAS 7

void llenarMatriz(int matriz[FILAS][COLUMNAS]) 
{
    srand(time(NULL));
    int i, j;
    for (i = 0; i < FILAS; i++) 
	{
        for (j = 0; j < COLUMNAS; j++) 
		{
            matriz[i][j] = rand() % 10;
        }
    }
}

void imprimirMatriz(int matriz[FILAS][COLUMNAS]) 
{
    int i, j;
    for (i = 0; i < FILAS; i++) 
	{
        for (j = 0; j < COLUMNAS; j++) 
		{
            printf("%2d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int sumaDiagonalPrincipal(int matriz[FILAS][COLUMNAS]) 
{
    int suma = 0, i;
    for (i = 0; i < FILAS && i < COLUMNAS; i++) 
	{
        suma += matriz[i][i];
    }
    return suma;
}

int sumaPrimeraFila(int matriz[FILAS][COLUMNAS])
{
    int suma = 0, j;
    for (j = 0; j < COLUMNAS; j++) 
	{
        suma += matriz[0][j];
    }
    return suma;
}

int sumaUltimaColumna(int matriz[FILAS][COLUMNAS]) 
{
    int suma = 0, i;
    for (i = 0; i < FILAS; i++) 
	{
        suma += matriz[i][COLUMNAS - 1];
    }
    return suma;
}

int sumaFilasPares(int matriz[FILAS][COLUMNAS]) 
{
    int suma = 0, i, j;
    for (i = 0; i < FILAS; i += 2) 
	{
        for (j = 0; j < COLUMNAS; j++) 
		{
            suma += matriz[i][j];
        }
    }
    return suma;
}

int sumaColumnasImpares(int matriz[FILAS][COLUMNAS]) 
{
    int suma = 0, j, i;
    for (j = 1; j < COLUMNAS; j += 2) 
	{
        for (i = 0; i < FILAS; i++) 
		{
            suma += matriz[i][j];
        }
    }
    return suma;
}

int sumaTriangularSuperiorSinDiagonal(int matriz[FILAS][COLUMNAS]) 
{
    int suma = 0, i, j;
    for (i = 0; i < FILAS; i++) 
	{
        for (j = i + 1; j < COLUMNAS; j++) 
		{
            suma += matriz[i][j];
        }
    }
    return suma;
}

int sumaTriangularInferiorSinDiagonal(int matriz[FILAS][COLUMNAS]) 
{
    int suma = 0, i, j;
    for (i = 0; i < FILAS; i++) 
	{
        for (j = 0; j < i; j++) 
		{
            suma += matriz[i][j];
        }
    }
    return suma;
}

int* sumaCadaFila(int matriz[FILAS][COLUMNAS]) 
{
    int* sumaFilas = malloc(FILAS * sizeof(int));
    int i;
    for (i = 0; i < FILAS; i++) 
	{
        sumaFilas[i] = 0;
        int j;
        for (j = 0; j < COLUMNAS; j++) 
		{
            sumaFilas[i] += matriz[i][j];
        }
    }
    return sumaFilas;
}

int* sumaCadaColumna(int matriz[FILAS][COLUMNAS]) 
{
    int* sumaColumnas = malloc(COLUMNAS * sizeof(int));
    int j;
    for (j = 0; j < COLUMNAS; j++) 
	{
        sumaColumnas[j] = 0;
        int i;
        for (i = 0; i < FILAS; i++) 
		{
            sumaColumnas[j] += matriz[i][j];
        }
    }
    return sumaColumnas;
}

int sumaTotalFilas(int* sumaFilas) 
{
    int suma = 0, i;
    for (i = 0; i < FILAS; i++) 
	{
        suma += sumaFilas[i];
    }
    return suma;
}

int sumaTotalColumnas(int* sumaColumnas) 

{
    int suma = 0, j;
    for (j = 0; j < COLUMNAS; j++) 
	{
        suma += sumaColumnas[j];
    }
    return suma;
}

int main() 
{
    int matriz[FILAS][COLUMNAS];

    llenarMatriz(matriz);

    printf("Matriz:\n");
    imprimirMatriz(matriz);
    printf("\n");

    printf("Suma de la diagonal principal: %d\n", sumaDiagonalPrincipal(matriz));
    printf("Suma de la primera fila: %d\n", sumaPrimeraFila(matriz));
    printf("Suma de la ultima columna: %d\n", sumaUltimaColumna(matriz));
    printf("Suma de las filas pares: %d\n", sumaFilasPares(matriz));
    printf("Suma de las columnas impares: %d\n", sumaColumnasImpares(matriz));
    printf("Suma del triangular superior: %d\n", sumaTriangularSuperiorSinDiagonal(matriz));
    printf("Suma del triangular inferior: %d\n", sumaTriangularInferiorSinDiagonal(matriz));

    


    return 0;
}

