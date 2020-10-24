#include <bits/stdc++.h>
#include <iostream>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

typedef pair<int, int> pii;
#define MAXN 1010
#define INF 99999999
#define F first
#define S second

int n, m;
vector<pii> g[MAXN];

int prim(){
  int dist[n];
  bool visited[n];
  for (size_t i = 0; i < n; i++){
    dist[i] = INF;
    visited[i] = false;
  }
  dist[0] = 0;

  priority_queue<pii, vector<pii>, greater<pii>> fila;
  fila.push(pii(dist[0], 0));

  while(true){
    int current = -1;

    while(!fila.empty()){
      int idx = fila.top().S;
      fila.pop();

      if(!visited[idx]){
        current = idx;
        break;
      }
    }

    if(current == -1) break;

    visited[current] = true;

    for(auto const &x : g[current]){
      int d = x.F;
      int idx = x.S;

      if(d < dist[idx] && !visited[idx]){
        dist[idx] = d;
        fila.push(pii(d, idx));
      }
    }
  }

  int total = 0;
  for (size_t i = 0; i < n; i++) total += dist[i];
  return total;
}

int main(){_;
  cin >> n >> m;

  for (size_t i = 0; i < m; i++) {
    int p, q, u; cin >> p >> q >> u;
    g[p].push_back(pii(u, q));
    g[q].push_back(pii(u, p));
  }

  cout << prim() << endl;

  return 0;
}
