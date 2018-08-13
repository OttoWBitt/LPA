/*
Nome : Otto Bittencourt
 */
#include <cstdio>
#include <iostream>

using namespace std;

struct Pedido {
	int tempo;
	int pizzas;
};

struct Pedido array[21];
int matriz[21][31];

int main(){
	int n, p;

	while (cin >> n && n) {
		
		cin >> p;

		for (int i = 1; i <= n; i++){
			scanf("%d %d", &array[i].tempo, &array[i].pizzas);
		}

		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= p; j++) {
		
				if (i == 0 || j == 0)
					matriz[i][j] = 0;
				else {
		
					if (array[i].pizzas > j){
						matriz[i][j] = matriz[i - 1][j];
					}
					else{
						matriz[i][j] = max(matriz[i - 1][j - array[i].pizzas] + array[i].tempo, matriz[i - 1][j]);
					}
				}
			}
		}

		printf("%d min.\n", matriz[n][p]);
	}

}