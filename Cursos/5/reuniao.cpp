#include <bits/stdc++.h>
#include <iostream>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

#define MAXN 101
#define INF 99999999

int n, m;
int mat[MAXN][MAXN];

int main(){_;
  cin >> n >> m;

  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < n; j++) {
      mat[i][j] = (i == j) ? 0 : INF;
    }
  }

  for (int u, v, w, i = 0; i < m; i++) {
    cin >> u >> v >> w;
    mat[u][v] = w;
    mat[v][u] = w;
  }

  for (size_t k = 0; k < n; k++) {
    for (size_t i = 0; i < n; i++) {
      for (size_t j = 0; j < n; j++) {
        mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
      }
    }
  }

  int menor = INF;
  for (size_t i = 0; i < n; i++) {
    int maiorLocal = 0;
    for (size_t j = 0; j < n; j++) {
      maiorLocal = max(maiorLocal, mat[i][j]);
    }
    menor = min(menor, maiorLocal);
  }

  cout << menor << endl;

  return 0;
}
