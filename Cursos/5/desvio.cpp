#include <iostream>
#include <vector>
#include <queue>
#define MAX 300
#define INF 999999
using namespace std;
typedef pair<int, int> pii;

int n, m, c, k;
vector<pii> grafo[MAX];

int dijkstra(){
  bool visited[n];
  int dist[n];

  for (size_t i = 0; i < n; i++) {
    visited[i] = false;
    dist[i] = INF;
  }
  dist[k] = 0;

  priority_queue<pii, vector<pii>, greater<pii>> fila;
  fila.push(pii(0, k));

  while (!fila.empty()) {
    int minValue = fila.top().first;
    int index = fila.top().second;
    fila.pop();
    visited[index] = true;

    if(dist[index] < minValue) continue;

    if(index < c){
      pii next = grafo[index][index+1]
      int newDist = dist[index] + grafo[index+].first;
      if(newDist < dist[grafo[index+1]]){
        dist[grafo[index+1]] = newDist;
        fila.push(pii(newDist, grafo[index+1]));
      }
      continue;
    }

    for(const auto& v : grafo[index]){
      if(visited[v.second]) continue;

      int newDist = dist[index] + v.first;
      if(newDist < dist[v.second]){
        dist[v.second] = newDist;
        fila.push(pii(newDist, v.second));
      }
    }
  }

  // for (size_t i = 0; i < n; i++) {
  //   cout << dist[i] << endl;
  // }

  return dist[c-1];
}

int main(){
  int u, v, p, respostas[100], count = 0;
  while (true) {
    for (size_t i = 0; i < n; i++) {
      grafo[i].erase(grafo[i].begin(), grafo[i].end());
    }
    cin >> n >> m >> c >> k;

    if(m == 0) break;

    for (size_t i = 0; i < m; i++) {
      cin >> u >> v >> p;

      grafo[u].push_back(pii(p, v));
      grafo[v].push_back(pii(p, u));
    }

    respostas[count] = dijkstra();
    count++;
  }

  for (size_t i = 0; i < count; i++) {
    cout << respostas[i] << endl;
  }

  return 0;
}
