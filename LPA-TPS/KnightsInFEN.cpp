/*
 Nome: Otto Bittencourt
 Matricula: 504654
 LPA
 */
#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int loop = 0;

char board[5][5];

char target[5][5] = {

	'1', '1', '1', '1', '1',
	'0', '1', '1', '1', '1',
	'0', '0', ' ', '1', '1',
	'0', '0', '0', '0', '1',
	'0', '0', '0', '0', '0',
};

int cont;

int movex[8] = { 1, 2, 2, 1, -1, -2, -2, -1,};
int movey[8] = { -2, -1, 1, 2, 2, 1, -1, -2,};

bool ehValido(int pri, int seg) {

	if (pri >= 5 || pri < 0)return false;
	if (seg >= 5 || seg < 0)return false;
	return true;
}

void dfs(int cont2, int x, int y) {

	if (cont2 == 11){
		return;
	}
	if (memcmp(board, target, sizeof(board)) == 0) {
		cont = min(cont, cont2);
		return;
	}
	for (int i = 0; i < 8; i++) {
		int xx = x + movex[i];
		int yy = y + movey[i];
		if (ehValido(xx, yy)) {
			swap(board[x][y], board[xx][yy]);
			dfs(cont2 + 1, xx, yy);
			loop++;
			swap(board[x][y], board[xx][yy]);
		}
	}
}

int main() {

	int numeroDeCasos;
	cin >> numeroDeCasos;
	string ent1;
	getline(cin, ent1);

	for (int i = 0; i < numeroDeCasos; i++) {

		int x, y;
		for (int j = 0; j < 5; j++) {

			getline(cin, ent1);
			for (int k = 0; k < 5; k++) {

				board[j][k] = ent1[k];
				if (ent1[k] == ' ') {

					x = j;
					y = k;
				}
			}
		}

		cont = 11;

		dfs(0, x, y);

		if (cont == 11) {
			printf("Unsolvable in less than 11 move(s).\n");
		}
		else {
			printf("Solvable in %d move(s).\n", cont);
		}
		//printf("contador eh %d \n",loop);
	}
	return 0;
}
