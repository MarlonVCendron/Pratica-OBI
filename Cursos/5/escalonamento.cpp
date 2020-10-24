#include <bits/stdc++.h>
#include <iostream>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

#define MAXN 50010

int n, m;
vector<int> g[MAXN];
int grau[MAXN] = {};
vector<int> lista;

int main(){_;
  cin >> n >> m;

  for (int a, b, i = 0; i < m; i++) {
    cin >> a >> b;

    grau[b]++;
    g[a].push_back(b);
  }

  for (size_t i = 0; i < n; i++) if(grau[i] == 0) lista.push_back(i);

  int ini = 0;
  while(ini < lista.size()){
    int atual = lista[ini];
    ini++;

    for(auto const &x : g[atual]){
      grau[x]--;
      if(grau[x] == 0){
        bool inserido = false;
        for (size_t i = ini; i < lista.size(); i++) {
          if(x < lista[i]){
            lista.insert(lista.begin()+i, x);
            inserido = true;
            break;
          }
        }
        if(!inserido) lista.push_back(x);
      }
    }
  }

  if(lista.size() < n){
    cout << '*' << endl;
    return 0;
  }

  for (auto const &x : lista) {
    cout << x << endl;
  }

  return 0;
}
