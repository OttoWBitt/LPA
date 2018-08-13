/**
 * Otto Bittencourt
 */

#include <iostream>
#include <string.h>
#include<cstdio>
#include<cstring>

using namespace std;

#define MAXN 405
#define INF 20000000

long n, m, soma, a[MAXN][MAXN];
char nome[MAXN][12];
bool conexo;

int estacao(char s[]) {

	int k = 1;
	while (strcmp(s, nome[k]) != 0) k++;
	return k;
}

void prim() {

	long d[n + 3], min;
	int k, u, v;
	bool livrar[n + 3];
	
	for (k = 1; k <= n; k++) {
		livrar[k] = true; d[k] = INF;
	}
	d[1] = 0; soma = 0;
	for (k = 1; k <= n; k++) {
		u = 0; min = INF;
		for (v = 1; v <= n; v++) {
			if (livrar[v] && d[v] < min) {
				u = v; min = d[v];
			}
		}
		if (u == 0) return;
		livrar[u] = false;
		for (v = 1; v <= n; v++) {
			if (livrar[v] && a[u][v] < d[v]) {
				d[v] = a[u][v];
			}
		}
	}

	for (k = 2; k <= n; k++)
		soma += d[k];

	conexo = true;
}

main() {

	while (cin >> n >> m) {

		int i, u, v, price;
		char sa[12], sb[12];

		if (n == 0 && m == 0) break;

		for (int i = 1; i <= n; i++) {
			a[i][i] = 0;
			for (int j = i + 1; j <= n; j++) {
				a[i][j] = a[j][i] = INF;
			}
		}

		scanf(" ");
		for (i = 1; i <= n; i++) {
			cin >> nome[i];
		}
		for (i = 1; i <= m; i++) {
			scanf("%s %s %d", sa, sb, &price);
			u = estacao(sa); v = estacao(sb);
			a[u][v] = a[v][u] = price;
		}
		getchar(); fgets(sa,13,stdin);

		conexo = false;
		if (m >= n - 1) prim();

		if (conexo) cout << soma;
		else cout << "Impossible";
		cout << endl;
	}
}