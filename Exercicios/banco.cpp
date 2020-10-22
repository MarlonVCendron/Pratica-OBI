#include <bits/stdc++.h>
#include <iostream>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

typedef pair<int, int> pii;
#define F first
#define S second

int main(){_
  int c, n; cin >> c >> n;
  queue<pii> fila;

  int caixas[c];
  for (size_t i = 0; i < c; i++) caixas[i] = 0;

  for (int t, d, i = 0; i < n; i++) {
    cin >> t >> d;
    fila.push(pii(t, d));
  }

  int time = 0, total = 0;
  while (!fila.empty()) {
    if(fila.front().F <= time){
      for (size_t i = 0; i < c; i++) {
        if(caixas[i] == 0){
          if(time - fila.front().F > 20){
            total++;
          }

          caixas[i] = fila.front().S;
          fila.pop();

          goto skip;
        }
      }
    }

    for (size_t i = 0; i < c; i++) if(caixas[i] > 0) caixas[i]--;
    time++;

    skip:;
  }

  cout << total << endl;

  return 0;
}
