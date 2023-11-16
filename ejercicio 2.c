#include <stdio.h>

#define N 3

void imprimirMatriz(int matriz[N][N]) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf(" |%d| ", matriz[i][j]);
        }
        printf("\n");
    }
}

void imprimirSumaDiagonales(int matriz[N][N]) {
    int sumaDiagonalP = 0;
    int sumaDiagonalSecundaria = 0;
	int i;
	
    for (i = 0; i < N; i++) {
        sumaDiagonalP += matriz[i][i];
        sumaDiagonalSecundaria += matriz[i][N - 1 - i];
    }

    printf("\nSuma de la diagonal principal: %d\n", sumaDiagonalP);
    printf("Suma de la diagonal secundaria: %d\n", sumaDiagonalSecundaria);
}

int esMatrizMagica(int matriz[N][N]) 
{
    int sumaFila = 0, j, i;
    for (j = 0; j < N; j++) 
	{
        sumaFila += matriz[0][j];
    }
    for (i = 1; i < N; i++) 
	{
        int sumaFilaActual = 0;
        for (j = 0; j < N; j++) 
		{
            sumaFilaActual += matriz[i][j];
        }
        if (sumaFilaActual != sumaFila) 
		{
            return 0;
        }
    }

    for (j = 0; j < N; j++) 
	{
        int sumaColumna = 0;
        for (i = 0; i < N; i++) 
		{
            sumaColumna += matriz[i][j];
        }
        if (sumaColumna != sumaFila) 
		
		{
            return 0;
        }
    }

    int sumaDiagonalP = 0;
    for (i = 0; i < N; i++) 
	{
        sumaDiagonalP += matriz[i][i];
    }
    if (sumaDiagonalP != sumaFila) 
	{
        return 0;
    }

    int sumaDiagonalSecundaria = 0;
    for (i = 0; i < N; i++) 
	{
        sumaDiagonalSecundaria += matriz[i][N - 1 - i];
    }
    if (sumaDiagonalSecundaria != sumaFila) 
	{
        return 0;
    }

    return 1;
}

int main() 
{
    int matriz[N][N];

    printf("Ingrese los elementos de la matriz de 3x3:\n");
    int i, j;
    for (i = 0; i < N; i++) 
	{
        for (j = 0; j < N; j++) 
		{
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("\nMatriz ingresada:\n\n");
    imprimirMatriz(matriz);

    if (esMatrizMagica(matriz)) 
	{
        printf("\nLa matriz es magica.\n\n");

        printf("\nSuma de cada fila:\n\n");

        for (i = 0; i < N; i++) {
            int sumaFila = 0;
            for (j = 0; j < N; j++) {
                sumaFila += matriz[i][j];
            }
            printf("Fila %d: %d\n", i + 1, sumaFila);
        }

        printf("\nSuma de cada columna:\n\n");

        for (j = 0; j < N; j++) 
		{
            int sumaColumna = 0;
            for (i = 0; i < N; i++) 
			{
                sumaColumna += matriz[i][j];
            }
            printf("Columna %d: %d\n", j + 1, sumaColumna);
        }

        
        imprimirSumaDiagonales(matriz);
    } 
	else 
	{
        printf("La matriz no es magica.\n");
    }

    return 0;
}

