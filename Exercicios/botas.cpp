#include <bits/stdc++.h>
#include <iostream>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

#define F first
#define S second

int main(){_;
  int n; cin >> n;
  map<int, int> botas;
  map<int, int> tamanhos;

  for (size_t i = 0; i < n; i++) {
    int m;
    char l;
    cin >> m >> l;

    botas[m]++;
    if(l == 'E') tamanhos[m]++;
    else tamanhos[m]--;
  }

  int total = 0;

  for (auto it = botas.begin(); it != botas.end(); it++) {
    // cout << it->F << " " << it->S << ": " << tamanhos[it->F] << endl;
    total += it->S - abs(tamanhos[it->F]);
  }

  cout << total/2 << endl;

  return 0;
}
