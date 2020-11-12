#include <bits/stdc++.h>
#include <iostream>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

#define MAXN 110

int n, m;
vector<int> g[MAXN];
int cores[MAXN] = {};

void colorir(int p, int q, int c){
  bool visited[n];
  int prev[n];

  for (size_t i = 0; i < n; i++) {
    visited[i] = false;
    prev[i] = -1;
  }

  queue<int> fila;
  fila.push(p);

  while(!fila.empty()){
    int atual = fila.front();
    fila.pop();

    visited[atual] = true;

    for(const auto &x : g[atual]){
      if(!visited[x]){
        prev[x] = atual;
        if(x == q) goto final;
        fila.push(x);
      }
    }
  }

  final:;
  
  for (int i = q; i != -1; i = prev[i]) {
    cores[i] = c;
  }
}

int main(){_;
  cin >> n >> m;

  for (int a, b, i = 0; i < n-1; i++) {
    cin >> a >> b;
    g[a-1].push_back(b-1);
    g[b-1].push_back(a-1);
  }

  // for (size_t i = 0; i < n; i++) {
  //   cout << i << ": ";
  //   for (size_t j = 0; j < g[i].size(); j++) {
  //     cout << g[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  for (int p, q, c, i = 0; i < m; i++) {
    cin >> p >> q >> c;
    colorir(p-1, q-1, c);
  }

  for (size_t i = 0; i < n; i++) cout << cores[i] << " ";
  cout << endl;

  return 0;
}
