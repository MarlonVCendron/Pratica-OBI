#include <bits/stdc++.h>
#include <iostream>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

typedef pair<int, int> pii;
#define MAXN 110
#define F first
#define S second

int n, x, y;
int mat[MAXN][MAXN];
vector<pii> g[MAXN];

int idx(int i, int j){
  return i*n + j;
}

int bfs(int s){
  bool visited[n];
  for (size_t i = 0; i < n; i++) {
    visited[i] = false;
  }
  queue<pii> fila;
  fila.push(s);

  while (!fila.empty()) {
    int index = fila.top().F;
    int num = fila.top().S;
    fila.pop();

    visited[index] = true;

    for(auto const &v : g[index]){
      if(visited[v.F]) continue;
    }
  }
}

int main(){_;
  cin >> n >> x >> y;
  for (size_t i = 0; i < n; i++) cin >> mat[i][j];

  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < n; j++) {
      int di[] = {1, 0, -1, 0};
      int dj[] = {0, 1, 0, -1};
      for (size_t k = 0; k < 4; k++) {
        int ii = i + di[k];
        int jj = j + dj[k];
        if(ii<0 || jj<0 || ii>=n || jj>=n) continue;
        g[idx(i,j)].push_back(pii(idx(ii,jj), mat[ii][jj]));
      }
    }
  }

  cout << bfs(idx(x,y)) << endl;

  return 0;
}
