/*
 Nome: Otto Bittencourt
 504654
 */
#include <iostream>
#include <queue>
#include <cstdio>
#define MAXV 100100

using namespace std;

typedef vector<int> vi;
typedef pair<int, string> is;
typedef unsigned long long int64;

typedef struct no {
	int64 to, custo;
	no ( int64 to = 0, int64 custo = 0 ) : to(to), custo(custo) {}
} ii;

vector < vector<ii> > grafo;

int noPai[MAXV], tamanhoArvore[MAXV], corrente[MAXV], correnteLider[MAXV];
int correnteCC;
int64 acc[MAXV];

void BFS() {
	queue <ii> bfs;
	bfs.push( ii(1, 0) );
	while ( !bfs.empty() ) {
		ii atual = bfs.front();
		bfs.pop();
		acc[atual.to - 1] = atual.custo;
		for ( int i = 0; i < grafo[atual.to].size(); ++i ) {
			int dest = grafo[atual.to][i].to;
			bfs.push( ii(dest, atual.custo + grafo[atual.to][i].custo) );
		}
	}
}

void explorar ( int x, int dad ) {
	if ( noPai[x] != -1 ) return;
	noPai[x] = dad;
	tamanhoArvore[x] = 1;
	for ( int i = 0; i < grafo[x].size(); ++i ) {
		if ( grafo[x][i].to != dad ) {
			explorar( grafo[x][i].to, x );
			tamanhoArvore[x] += tamanhoArvore[grafo[x][i].to];
		}
	}
}

void heavy_light ( int x, int dad, int k, int p ) {
	if ( p == 0 ) {
		k = correnteCC++;
		correnteLider[k] = x;
	}
	corrente[x] = k;
	int mx = -1;

	for ( int i = 0; i < grafo[x].size(); ++i ) {

		if ( grafo[x][i].to != dad && ( mx == -1 || tamanhoArvore[grafo[x][i].to] > tamanhoArvore[grafo[x][mx].to] ) ) {
			mx = i;
		}
	}

	if ( mx != -1 ) {
		heavy_light( grafo[x][mx].to, x, k, p + 1 );
	}
	for ( int i = 0; i < grafo[x].size(); ++i ) {

		if ( grafo[x][i].to != dad && i != mx ) {
			heavy_light( grafo[x][i].to, x, -1, 0 );
		}
	}

}

int lca ( int a, int b ) {
	while ( corrente[a] != corrente[b] ) {
		if ( tamanhoArvore[correnteLider[corrente[a]]] >= tamanhoArvore[correnteLider[corrente[b]]] ) {
			b = noPai[correnteLider[corrente[b]]];
		}
		else {
			a = noPai[correnteLider[corrente[a]]];
		}
	}
	if ( tamanhoArvore[a] < tamanhoArvore[b] ) return b;
	return a;
}

int main() {
	int de, para, custo, m, n;
	while ( scanf("%d", &m) && m ) {
		grafo.resize(m + 1);
		for ( int i = 0; i <= m; ++i ) {
			noPai[i] = noPai[i + 1] = -1;
			acc[i] = corrente[i] = 0;
		}

		for ( int i = 1; i < m; ++i ) {
			scanf("%d %d", &para, &custo);
			grafo[para + 1].push_back( ii(i + 1, custo) );
		}
		correnteCC = 0;
		explorar( 1, 0 );
		heavy_light( 1, 0, -1, 0 );
		BFS();
		scanf("%d", &n);
		for ( int i = 0; i < n; ++i ) {
			scanf("%d %d", &de, &para);
			int l = lca(de + 1, para + 1);
			if ( i == 0 ) {
				printf("%llu", acc[de] + acc[para] - 2 * acc[l - 1]);
			}
			else {
				printf(" %llu", acc[de] + acc[para] - 2 * acc[l - 1]);
			}
		}
		printf("\n");
		grafo.clear();
	}
	return 0;
}