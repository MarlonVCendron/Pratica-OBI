#include <iostream>
#include <vector>
#include <queue>
#include <stdbool.h>
using namespace std;

#define MAXL 110
#define MAXS 10010

int n, m, k, l, c, total = 0;
char mat[MAXL][MAXL];
vector<int> g[MAXS];
bool visited[MAXS];

int idx(int i, int j){
  return i*m + j;
}

int geti(int x){
  return x/m;
}

int getj(int x){
  return x % m;
}

int main(){
  cin >> n >> m;

  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < m; j++) {
      cin >> mat[i][j];
    }
  }

  cin >> k;
  for (size_t i = 0; i < k; i++) {
    cin >> l >> c;
    if(mat[l-1][c-1] == '#') mat[l-1][c-1] = 'x';
  }

  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < m; j++) {
      if (mat[i][j] == '.') {
        visited[idx(i,j)] = 1;
        continue;
      }

      int di[] = {-1, 1, 0, 0};
      int dj[] = {0, 0, -1, 1};

      for (size_t k = 0; k < 4; k++) {
        int ii = i + di[k];
        int jj = j + dj[k];

        if(ii < 0 || jj < 0 || ii >= n || jj >= m) continue;

        if(mat[ii][jj] != '.'){
          g[idx(i, j)].push_back(idx(ii, jj));
        }
      }
    }
  }

  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < m; j++) {
      int currentIndex = idx(i,j);
      if(visited[currentIndex]) continue;

      bool afundado = 1;
      if(mat[i][j] == '#') afundado = 0;

      visited[currentIndex] = 1;

      queue<int> fila;
      fila.push(currentIndex);

      while (!fila.empty()) {
        vector<int> neighbors = g[fila.front()];
        fila.pop();
        for(const auto &n : neighbors){
          if(visited[n]) continue;
          visited[n] = 1;
          fila.push(n);
          if(mat[geti(n)][getj(n)] == '#') afundado = 0;
        }
      }
      if(afundado) total++;
    }
  }

  cout << total << endl;

  return 0;
}
