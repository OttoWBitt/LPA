/*
*Nome:Otto Bittencourt
*LPA
*Matricula: 504654
*/
#include<cstdio>

using namespace std;

const int numMoedas = 11;

const int tamanhoDoArray = 30001;

int moedas[] = {10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5};

long long possibilidades[tamanhoDoArray];

void gerarArray() {

	possibilidades[0] = 1;
	for ( int i = 0; i < numMoedas; i++) {
		int posicao = moedas[i];
		for (int k = posicao; k < tamanhoDoArray; k ++) {
			possibilidades[k] += possibilidades[ k - posicao ];
		}
	}
}

int main() {

	gerarArray();

	float entrada;

	while (scanf("%f", &entrada) == 1 && entrada) {
		unsigned moneda = (unsigned)((entrada + 0.001) * 100);
		printf("%6.2f%17lld\n", entrada, possibilidades[moneda]);
	}

	return 0;
}