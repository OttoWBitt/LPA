/**
 * Nome: Otto Bittencourt
 * LPA
 */
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

struct infoQuina {
    int comeco;
    int fim;
    int dist;
} a [1000000];

int pai [1000000];
bool bol [1000000];
vector <int> quina [1000000];
int n, m;

void dfs (int u)
{
    bol [u] = true;

    for ( size_t i = 0; i < quina [u].size (); i++ ) {
        if ( !bol [quina [u] [i]] ) dfs (quina [u] [i]);
    }
}

bool cmp (infoQuina x, infoQuina y)
{
    if ( x.dist < y.dist ) {
        return true;
    }
    return false;
}

int paiDe (int n)
{
    if ( n == pai [n] ) {
        return n;
    }
    return pai [n] = paiDe ( pai [n] );
}

int main ()
{
    while ( scanf ("%d %d", &n, &m) ) {
        if ( n == 0 && m == 0 ) break;

        for ( int i = 0; i < n; i++ ) {
            bol [i] = false;
            quina [i].clear ();
            pai [i] = i;
        }

        for ( int i = 0; i < m; i++ ) {
            scanf ("%d %d %d", &a [i].comeco, &a [i].fim, &a [i].dist);
            quina [a [i].comeco].push_back (a [i].fim);
            quina [a [i].fim].push_back (a [i].comeco);
        }

        dfs (0);

        bool impossible = false;

        for ( int i = 0; i < n; i++ ) {
            if ( !bol [i] ) {
                impossible = true;
                break;
            }
        }

        if (impossible) {
            printf ("IMPOSSIBLE\n");
            continue;
        }

        sort (a, a + m, cmp);

        int distMaxima = 0;
        int quinaSelecionada = m - 1;

        for ( int i = 0; i < m && quinaSelecionada; i++ ) {
            int p = paiDe (a [i].comeco);
            int q = paiDe (a [i].fim);
            if ( p != q ) {
                pai [p] = q;
                quinaSelecionada--;
                if ( a [i].dist > distMaxima ) distMaxima = a [i].dist;
            }
        }

        printf ("%d\n", distMaxima);
    }

    return 0;
}