
// CÓDIGO LIXO, PASSA DO TEMPO LIMITE

#include <bits/stdc++.h>
#include <iostream>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

typedef pair<int, int> pii;
#define MAXN 100010
#define F first
#define S second

int n;
vector<pii> g[MAXN];

bool importantPath(int s, int e){
  bool important = false;
  bool visited[n] = {};
  queue<pii> fila;
  fila.push(pii(s, 0));

  while (!fila.empty()) {
    int idx = fila.front().F;
    int imp = fila.front().S;

    if(idx == e){
      important = imp;
      break;
    }

    fila.pop();
    visited[idx] = true;

    for(auto const &x : g[idx]){
      if(!visited[x.F]){
        fila.push(pii(x.F, ((x.S+imp)>0)));
      }
    }
  }

  return important;
}

int main(){_;
  cin >> n;

  for (int a, b, c, i = 0; i < n-1; i++) {
    cin >> a >> b >> c;
    g[a-1].push_back(pii(b-1, c));
    g[b-1].push_back(pii(a-1, c));
  }

  int total = 0;
  for (size_t i = 0; i < n; i++) {
    for (size_t j = i+1; j < n; j++) {
      if(importantPath(i, j)) total++;
    }
  }

  cout << total << endl;

  return 0;
}
