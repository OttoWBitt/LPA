/**
 * Otto Bittencourt
 */
#include <bits/stdc++.h>
using namespace std;

int tipo[40][2];
int qtde[10];
bool found;
int numeroDeVoluntarios;

void verificar(int x) {

  if (x == numeroDeVoluntarios + 1) {

    found = true;
    return;
  }

  if (found) return;

  if (qtde[tipo[x][0]]) {

    --qtde[tipo[x][0]];
    verificar(x + 1);
    ++qtde[tipo[x][0]];
  }

  if (qtde[tipo[x][1]]) {

    --qtde[tipo[x][1]];
    verificar(x + 1);
    ++qtde[tipo[x][1]];
  }
}

int tamanhos(string s) {

  if (s == "XS") {
    return 1;
  }
  if (s == "S") {
    return 2;
  }
  if (s == "M") {
    return 3;
  }
  if (s == "L") {
    return 4;
  }
  if (s == "XL") {
    return 5;
  }
  return 6;
}

int main() {

  int casos;
  int numeroDeCamisas;
  string s1, s2;

  cin >> casos;

  while (casos--) {

    cin >> numeroDeCamisas >> numeroDeVoluntarios;

    for (int i = 0 ; i < 10; ++i) qtde[i] = numeroDeCamisas / 6;

    for (int i = 1 ; i <= numeroDeVoluntarios; ++i) {

      cin >> s1 >> s2;

      tipo[i][0] = tamanhos(s1);
      tipo[i][1] = tamanhos(s2);
    }

    found = false;
    verificar(1);

    if (found) cout << "YES\n";
    else cout << "NO\n";
  }
}