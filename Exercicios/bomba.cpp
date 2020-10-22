#include <bits/stdc++.h>
#include <iostream>
using namespace std;

typedef pair<int, int> pii;
#define MAXN 510
#define INF 9999
#define F first
#define S second

int n, e, s, m, tempo = 0;
vector<pii> g[MAXN];

int dijkstra(){
  int dist[n];
  bool visited[n];
  for (size_t i = 0; i < n; i++){
    dist[i] = INF;
    visited[i] = false;
  }
  dist[e] = 0;

  priority_queue<int, vector<int>, greater<int>> fila;
  fila.push(e);

  while(!fila.empty()){
    int current = fila.top();
    fila.pop();

    // if(current == s) break;

    visited[current] = true;

    cout << current << " (" << dist[current] << ")" << endl;

    for(auto const &x : g[current]){
      int nbr = x.F;
      int t = x.S;

      cout << "  " << nbr << " (" << t << ")" << endl;

      if(!visited[nbr]){
        cout << "    não visitado" << endl;
        if((t && dist[current] % 3 == 0) || (!t && dist[current] % 3 != 0)){
          cout << "    semáforo ok" << endl;
          if(dist[current] + 1 < dist[nbr]){
            dist[nbr] = dist[current] + 1;
          }
          fila.push(nbr);
        }
      }
    }
  }

  return(dist[s]);
}

int main(){
  cin >> n >> e >> s >> m;

  for (size_t i = 0; i < m; i++) {
    int a, b, t;
    cin >> a >> b >> t;

    g[a].push_back(pii(b, t));
  }



  // LEMBRAR DO T

  cout << dijkstra() << endl;
  // for (size_t i = 0; i < n; i++) {
  //   cout << i << ":  ";
  //   for(auto const &x : g[i]){
  //     cout << x.first << " ";
  //   }
  //   cout << endl;
  // }

  return 0;
}
