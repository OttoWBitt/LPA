/**
 * Otto Bittencourt
 * 504654
 */
#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

int main() {

  int numCasos;
  int numMoedas;
  int *moedas;
  int soma;
  int contarMoedas;

  scanf("%d", &numCasos);

  for (int i = 0; i < numCasos; i++) {

    scanf("%d", &numMoedas);
    moedas = new int[ numMoedas ];

    for (int i = 0; i < numMoedas; i++) {
      scanf("%d", &moedas[i] );
    }

    contarMoedas = 1;
    soma = moedas[0];
    for (int i = 1; i < numMoedas - 1; i++) {
      if ( soma + moedas[i] < moedas[i + 1] ) {
        soma += moedas[i];
        contarMoedas++;
      }
    }

    printf("%d\n", contarMoedas + 1);
  }
}