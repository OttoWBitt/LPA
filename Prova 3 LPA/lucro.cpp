/*
Nome : Otto Bittencourt
 */

#include <bits/stdc++.h>

using namespace std;

int dias;
int receitaDoDia[50];

int calcularLucro(){

	int aux;
	int maximoDeLucro;

	aux = maximoDeLucro = 0;
	
	for (int i = 0 ; i < dias ; i++){

		aux = max(0, aux + receitaDoDia[i]);
		maximoDeLucro = max(maximoDeLucro, aux);
	}
	return maximoDeLucro;
}

int main(){

	int custoPDia;

	while(cin >> dias){

		cin >> custoPDia;

		for (int i = 0 ; i < dias ; i++){

			cin >> receitaDoDia[i];
			
			receitaDoDia[i]-= custoPDia;
		}
		cout << calcularLucro() << '\n';
	}
}