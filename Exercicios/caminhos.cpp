#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#define MAX 100100
#define INF 9999999
using namespace std;

typedef pair<int, int> pii;

int n, caminhos[MAX];

void dijkstra(int s, int* dist){
  bool visited[n];

  for (size_t i = 0; i < n; i++) {
    visited[i] = false;
    dist[i] = INF;
  }
  dist[s] = 0;

  priority_queue<pii, vector<pii>, greater<pii>> fila;
  fila.push(pii(0, s));

  while (!fila.empty()) {
    int minValue = fila.top().first;
    int index = fila.top().second;
    fila.pop();
    visited[index] = true;

    if(dist[index] < minValue) continue;

    if(visited[caminhos[index]]) continue;

    int newDist = dist[index] + 1;
    if(newDist < dist[caminhos[index]]){
      dist[caminhos[index]] = newDist;
      fila.push(pii(newDist, caminhos[index]));
    }
  }
}

int main(){
  int f;
  cin >> n;
  int distancias[n][n];

  for (size_t i = 0; i < n; i++) {
    cin >> f;
    caminhos[i] = f-1;
  }

  for (size_t i = 0; i < n; i++) {
    dijkstra(i , distancias[i]);
  }

  int q, a, b;
  cin >> q;
  int respostas[q];

  for (size_t i = 0; i < q; i++) {
    cin >> a >> b;
    a--;
    b--;
    int menor = INF;
    for (size_t j = 0; j < n; j++) {
      if(distancias[a][j] == INF || distancias[b][j] == INF) continue;
      int d = max(distancias[a][j], distancias[b][j]);
      if(d < menor) menor = d;
    }
    respostas[i] = menor;
  }

  for (size_t i = 0; i < q; i++) {
    cout << respostas[i] << endl;
  }

  return 0;
}
