/*
* Otto Bittencourt
* 504654
* LPA
 */
#include<stdio.h>
#include<string.h>

#define N 100000

static int arrayPai[N];
static int rankArray[N];
static int elementosArray[N];

int maximo;

int acharSet(int x) {
    if ( x != arrayPai[x] )
        arrayPai[x] = acharSet( arrayPai[x] );
    return arrayPai[x];
}

void Link(int x, int y) {

    if ( !(acharSet(x) == acharSet(y)) ) {

        if ( rankArray[x] > rankArray[y] ) {
            arrayPai[y] = x;
            elementosArray[x] += elementosArray[y];
            maximo = ( maximo < elementosArray[x] ) ? elementosArray[x] : maximo;
        }
        else {
            arrayPai[x] = y;
            elementosArray[y] += elementosArray[x];
            maximo = ( maximo < elementosArray[y] ) ? elementosArray[y] : maximo;

            if (rankArray[x] == rankArray[y]){
                rankArray[y] = rankArray[y] + 1;
            }
        }

    }
}

int main() {

    int n, m;
    int i, j;
    int cont;
    scanf("%d", &cont);

    while ( cont-- ) {

        scanf("%d%d", &n, &m);

        for (int o = 0; o < n; ++o) {
            arrayPai[o]  = o;
            rankArray[o] = 0;
            elementosArray[o] = 1;
        }

        maximo = 1;

        while (m--) {
            scanf("%d%d", &i, &j);
            --i, --j;
            Link( acharSet(i), acharSet(j) );
        }

        printf("%d\n", maximo);

    }


    return 0;
}