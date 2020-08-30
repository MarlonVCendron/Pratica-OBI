#include <iostream>
#include <vector>
#include <queue>
#include <stdbool.h>
using namespace std;

typedef pair<int, int> pii;
#define F first
#define S second

int n, m, u, v, w, q, a, x, k, r = 0;

int main(){
  cin >> n >> m;

  vector<pii> g[n];
  int values[n];
  for (size_t i = 0; i < n; i++) cin >> values[i];

  for (size_t i = 0; i < m; i++) {
    cin >> u >> v >> w;
    g[u-1].push_back(pii(v-1, w));
    g[v-1].push_back(pii(u-1, w));
  }

  cin >> q;

  bool visited[n];
  for (size_t i = 0; i < q; i++) {
    cin >> a >> x;
    a--;

    k = x + r;
    r = 0;

    for (size_t j = 0; j < n; j++) visited[j] = 0;

    queue<int> fila;
    fila.push(a);
    visited[a] = 1;

    while (!fila.empty()) {
      int curr = fila.front();
      fila.pop();

      r += values[curr];

      for (const auto &n : g[curr]) {
        if(visited[n.F]) continue;
        if(n.S > k) continue;

        fila.push(n.F);
        visited[n.F] = 1;
      }
    }

    cout << r << endl;
  }

  return 0;
}
