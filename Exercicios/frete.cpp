#include <iostream>
#include <vector>
#include <queue>
#include <stdbool.h>
using namespace std;

typedef pair<int, int> pii;
#define F first
#define S second
#define MAXN 100010
#define INF 999999

int n, m;
vector<pii> g[MAXN];

int dijkstra(){
  int dist[n];
  bool visited[n];

  for (size_t i = 0; i < n; i++) {
    dist[i] = INF;
    visited[i] = false;
  }
  dist[0] = 0;

  priority_queue<pii, vector<pii>, greater<pii>> fila;
  fila.push(pii(0,0));

  while (!fila.empty()) {
    int minValue = fila.top().F;
    int index = fila.top().S;
    fila.pop();
    visited[index] = true;

    if(dist[index] < minValue) continue;

    for (const auto &x : g[index]) {
      if(visited[x.S]) continue;

      int newDist = dist[index] + x.F;
      if(newDist < dist[x.S]){
        dist[x.S] = newDist;
        fila.push(pii(newDist, x.S));
      }
    }
  }

  return dist[n-1];
}

int main(){
  int a, b, c; cin >> n >> m;

  for (size_t i = 0; i < m; i++) {
    cin >> a >> b >> c;

    g[a-1].push_back(pii(c, b-1));
    g[b-1].push_back(pii(c, a-1));
  }

  cout << dijkstra() << endl;

  return 0;
}
