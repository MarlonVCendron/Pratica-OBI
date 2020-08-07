#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
  int n, m; cin >> n >> m;
  int mat[n][m];
  vector<int> g[n*m];
  int visited[n*m];

  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < m; j++) {
      cin >> mat[i][j];
      visited[j + m*i] = 0;
    }
  }

  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < m; j++) {
      if(!mat[i][j]) continue;

      int off_i[] = {-1, 1, 0, 0};
      int off_j[] = {0, 0, -1, 1};

      for (size_t k = 0; k < 4; k++) {
        int ii = i + off_i[k];
        int jj = j + off_j[k];

        if(ii < 0 || ii >= n || jj < 0 || jj >= m) continue;

        if(mat[ii][jj])
          g[j + m*i].push_back(jj + m*ii);

      }
    }
  }


  int total = 0;
  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < m; j++) {
      if(!mat[i][j]) continue;
      if(visited[j+m*i]) continue;

      queue<int> fila;
      fila.push(j + m*i);
      total++;

      while (!fila.empty()) {
        int idx = fila.front();
        fila.pop();

        visited[idx] = 1;

        for (size_t k = 0; k < g[idx].size(); k++) {
          if(!visited[g[idx][k]]){
            fila.push(g[idx][k]);
          }
        }
      }

    }
  }

  cout << total << endl;

  return 0;
}
