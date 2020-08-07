#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
  int l, c, s;
  cin >> l >> c;
  char mapa[l][c];
  int t = l*c;
  vector<int> grafo[t];

  for (size_t i = 0; i < l; i++) {
    for (size_t j = 0; j < c; j++) {
      cin >> mapa[i][j];
      if (mapa[i][j] == 'o') s = i*c+j;
    }
  }

  int dl[] = {-1, 1, 0, 0};
  int dc[] = {0, 0, -1, 1};

  for (size_t i = 0; i < l; i++) {
    for (size_t j = 0; j < c; j++) {
      if (mapa[i][j] == '.') continue;
      int idx = i*c+j;

      for (size_t k = 0; k < 4; k++) {
        int ii = i + dl[k];
        int jj = j + dc[k];

        if(ii < 0 || jj < 0 || ii >= l || jj >= c) continue;

        if (mapa[ii][jj] != '.') {
          grafo[idx].push_back(ii*c+jj);
        }
      }
    }
  }

  bool visited[t];
  for (size_t i = 0; i < t; i++) {
    visited[i] = false;
  }
  visited[s] = true;

  queue<int> fila;
  fila.push(s);
  int last = s;

  while (!fila.empty()) {
    vector<int> neighbours = grafo[fila.front()];
    fila.pop();
    for(auto& n:neighbours){
      if(visited[n]) continue;
      last = n;
      visited[n] = true;
      fila.push(last);
    }
  }

  cout << last/t+1 << " " << last % t + 1 << endl;

  return 0;
}
