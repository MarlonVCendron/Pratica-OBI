#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
#define INF 99999999;
#define MAXS 110

int n, size, mina[MAXS][MAXS];
vector<pii> grafo[MAXS*MAXS];

int rochaDijkstra(int s){
  bool visited[size];
  int prev[size], dist[size];
  for (size_t i = 0; i < size; i++) {
    visited[i] = false;
    prev[i] = -1;
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

    for(const auto& v: grafo[index]){
      if(visited[v.second]) continue;
      int newDist = dist[index] + v.first;
      if (newDist < dist[v.second]){
        prev[v.second] = index;
        dist[v.second] = newDist;
        fila.push(pii(newDist, v.second));
      }
    }
  }

  int rochas = 0;
  for (int i = size-1; i != -1; i = prev[i]) {
    if(mina[i/n][i % n] == 1){
      rochas++;
    }
  }

  return rochas;
}

int main(){
  cin >> n;
  size = n*n;
  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < n; j++) {
      cin >> mina[i][j];
    }
  }

  int dr[] = {-1, 1, 0, 0};
  int dc[] = {0, 0, -1, 1};

  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < n; j++) {
      int idx = i*n+j;
      for (size_t k = 0; k < 4; k++) {
        int ii = i + dr[k];
        int jj = j + dc[k];

        if(ii < 0 || jj < 0) continue;
        if(ii >= n || jj >= n) continue;

        int d = (mina[ii][jj] == 1) ? 200 : 1;

        grafo[idx].push_back(pii(d, ii*n+jj));
      }
    }
  }

  cout << rochaDijkstra(0) << endl;

  // for (size_t i = 0; i < size; i++) {
  //   cout << i << ":  ";
  //   for(const auto& v: grafo[i]){
  //     cout << "(" << v.first << " "<< v.second << ")  ";
  //   }
  //   cout << endl;
  // }

  return 0;
}
