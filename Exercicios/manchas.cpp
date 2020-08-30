#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAXS 1000010

int n, m;
vector<int> g[MAXS];
int visited[MAXS];

int indx(int i, int j){
  return m*i + j;
}

int main(){
  cin >> n >> m;
  int mat[n][m];

  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < m; j++) {
      cin >> mat[i][j];
      visited[indx(i, j)] = 0;
    }
  }

  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < m; j++) {
      if(!mat[i][j]){
        visited[indx(i, j)] = 1;
        continue;
      }

      int off_i[] = {-1, 1, 0, 0};
      int off_j[] = {0, 0, -1, 1};

      for (size_t k = 0; k < 4; k++) {
        int ii = i + off_i[k];
        int jj = j + off_j[k];

        if(ii < 0 || ii >= n || jj < 0 || jj >= m) continue;

        if(mat[ii][jj]){
          g[indx(i, j)].push_back(indx(ii, jj));
        }
      }
    }
  }


  int total = 0;
  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < m; j++) {
      int curr = indx(i, j);

      if(visited[curr]) continue;
      
      visited[curr] = 1;
      total++;

      queue<int> fila;
      fila.push(curr);

      while (!fila.empty()) {
        int idx = fila.front();
        fila.pop();

        vector<int> neighbors = g[idx];
        for (const auto &n : neighbors) {
          if(!visited[n]){
            visited[n] = 1;
            fila.push(n);
          }
        }
      }

    }
  }

  cout << total << endl;

  return 0;
}
