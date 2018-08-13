#include <iostream>
#include <cstring>
#include <queue>
#include <cstdio>
#define MAX 15
#define MAXIMO 1000000000

using namespace std;

struct Borda {
    int v, t, c;
    Borda(int v, int t, int c) : v(v), t(t), c(c) {}
    bool operator < (const Borda& that) const { 
        return c < that.c; 
    }
};

vector<Borda> Vetor[MAX];
priority_queue<Borda> fila;
int n, m, s, t;
int Matriz[MAX][60], Vetor2[MAX];

int dijkstra(int n,int m,int t) {

    for (int i = 1; i <= n; i++){
        cin >> Vetor2[i];
    }

    fila.push(Borda(1, t, 0));

    while (!fila.empty()) {
        Borda posicao = fila.top(); fila.pop();

        for (int j = 0; j < Vetor[posicao.v].size(); j++) {
           
            Borda borda = Vetor[posicao.v][j];
            int tanque = posicao.t - borda.c;
            if (tanque < 0){
                continue;
            }

            for (int i = 0; i <= t - tanque; i++) {
           
                int novaCapacidade = posicao.c + Vetor2[borda.v] * i;
           
                if (novaCapacidade < Matriz[borda.v][tanque + i]) {
                    Matriz[borda.v][tanque + i] = novaCapacidade;
                    fila.push(Borda(borda.v, tanque + i, novaCapacidade));
                }
            }
        }
    }
}

int main() {

    int cidadesNaRota, numeroDeEstradas, tamanhoDoTanque;
    
    while (scanf("%d %d %d", &cidadesNaRota, &numeroDeEstradas, &tamanhoDoTanque), cidadesNaRota | numeroDeEstradas | tamanhoDoTanque) {
        
        memset(Matriz, 0x3f, sizeof(Matriz));
        memset(Vetor, 0, sizeof(Vetor));
        
        fila = priority_queue<Borda>();

        for (int i = 0; i < numeroDeEstradas; i++) {
            int cidadeA, cidadeB, litrosGas;
            cin >> cidadeA >> cidadeB >> litrosGas;
            Vetor[cidadeA].push_back(Borda(cidadeB, 0, litrosGas));
            Vetor[cidadeB].push_back(Borda(cidadeA, 0, litrosGas));
        }

        dijkstra(cidadesNaRota,numeroDeEstradas,tamanhoDoTanque);

        int minn = MAXIMO;

        for (int i = 0; i < tamanhoDoTanque; ++i){
            minn = min(minn, Matriz[cidadesNaRota][i]);
        }

        if (minn < MAXIMO){
            cout << minn << endl;
        }
        else{
            cout << -1 << endl;
        }

    }
}