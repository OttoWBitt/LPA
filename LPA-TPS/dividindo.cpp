/*
*Nome:Otto Bittencourt
*504654
 */
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

int main() {
  int c;
  while (cin >> c) {
    vector<int> t(c); int aux;
    for (int i = 0 ; i < c; i++) {
      cin >> aux;
      t.push_back(aux);
    }
    sort(t.begin(), t.end(), greater<int>());
    int p1 = 0 , p2 = 0;
    for (int i = 0; i < t.size(); i++ ) {
      if ( p1 <= p2 ) {
        p1 += t[i];
      } else {
        p2 += t[i];
      }
    }
    int resp = ((p1 - p2) > 0) ? p1 - p2 : (-1) * (p1 - p2);
    cout << resp << endl;
  }
  return 0;
}