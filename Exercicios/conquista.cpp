#include <iostream>
#include <vector>
#include <queue>
#include <stdbool.h>
using namespace std;

typedef pair<int, int> pii;
#define F first
#define S second
#define MIND -1000
#define MAXN 3010
#define MAXS MAXN*MAXN

int n, m, s, mat[MAXN][MAXN];
vector<pii> g[MAXS];

int idx(int i, int j){
  return i*m + j;
}

int dijkstra(){
  bool visited[s];
  int dist[s];

  for (size_t i = 0; i < s; i++) {
    visited[i] = false;
    dist[i] = MIND;
  }
  dist[0] = mat[0][0];

  priority_queue<pii, vector<pii>, less<pii>> fila;
  fila.push(pii(dist[0], 0));

  while (!fila.empty()) {
    int maxValue = fila.top().F;
    int index = fila.top().S;

    // cout << "I: " << index << " (" << maxValue << ")" << endl;

    fila.pop();
    visited[index] = true;

    if(dist[index] > maxValue) continue;

    for (const auto &n : g[index]) {
      if(visited[n.S]) continue;

      int newDist = dist[index] + n.F;
      if(newDist > dist[n.S]){
        dist[n.S] = newDist;
        fila.push(pii(newDist, n.S));
        // cout << "  " << n.S << " (" << newDist << ")" << endl;
      }
    }
  }

  return dist[s-1];
}

int main(){
  cin >> n >> m;
  s = n*m;

  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < m; j++) {
      cin >> mat[i][j];
    }
  }

  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < m; j++) {
      int di[] = {-1, 1, 0, 0};
      int dj[] = {0, 0, -1, 1};

      for (size_t k = 0; k < 4; k++) {
        int ii = i + di[k];
        int jj = j + dj[k];

        if(ii < 0 || jj < 0 || ii >= n || jj >= m) continue;

        g[idx(i,j)].push_back(pii(mat[ii][jj], idx(ii, jj)));
      }
    }
  }

  cout << dijkstra() << endl;

  // for (size_t i = 0; i < n*m; i++) {
  //   cout << i << ": ";
  //   for (const auto &p : g[i]) {
  //     cout << p.F << "(" << p.S << "), ";
  //   }
  //   cout << endl;
  // }

  return 0;
}
