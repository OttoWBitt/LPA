/**
 * Otto Bittencourt
 */

#include<cstdio>
#include<algorithm>

using namespace std;

int matriz[100][100];
int numeroElementos;

int somaMaiorRetangulo() {
    int maiorSoma = matriz[0][0];

    int i = 0;
    int j = 0;
    int y = 0;

    while (i < numeroElementos) {

        j = i;

        while (j < numeroElementos) {
            
            for (int x = 0; x < numeroElementos; x++) {

                y = x;

                while (y < numeroElementos) {

                    int soma = 0;
                    for (int linhaInicio = i; linhaInicio <= j; linhaInicio++) {
                        for (int colunaInicio = x; colunaInicio <= y; colunaInicio++) {
                            soma += matriz[linhaInicio][colunaInicio];
                        }
                    }

                    int somaTemp = soma;
                    if (somaTemp > maiorSoma) {
                        maiorSoma = somaTemp;
                    }
                    y++;
                }
            }
            j++;
        }
        i++;
    }

    return maiorSoma;
}

int main() {


    while (scanf("%d", &numeroElementos) == 1) {
        for (int i = 0; i < numeroElementos; i++) {
            for (int j = 0; j < numeroElementos; j++) {
                scanf("%d/n", &matriz[i][j]);
            }
        }
        printf("%d\n", somaMaiorRetangulo());
    }

    return 0;
}