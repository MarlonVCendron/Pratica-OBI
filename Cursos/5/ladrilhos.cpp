#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
  int h, l, size; cin >> h >> l;
  size = h*l;
  int parede[h][l];
  vector<int> grafo[size];

  for (size_t i = 0; i < h; i++) {
    for (size_t j = 0; j < l; j++) {
      cin >> parede[i][j];
    }
  }

  int dr[] = {-1, 1, 0, 0};
  int dc[] = {0, 0, -1, 1};

  for (size_t i = 0; i < h; i++) {
    for (size_t j = 0; j < l; j++) {
      int idx = i*l+j;
      for (size_t k = 0; k < 4; k++) {
        int ii = i + dr[k];
        int jj = j + dc[k];

        if(ii < 0 || jj < 0) continue;
        if(ii >= h || jj >= l) continue;

        if(parede[i][j] == parede[ii][jj]){
          grafo[idx].push_back(ii*l+jj);
        }
      }
    }
  }

  bool visited[size];
  for (size_t i = 0; i < size; i++) {
    visited[i] = false;
  }

  int menor = 99999;
  int total;
  for (size_t i = 0; i < size; i++) {
    if(!visited[i]){
      visited[i] = true;
      total = 1;

      queue<int> fila;
      fila.push(i);

      while (!fila.empty()) {
        int node = fila.front();
        fila.pop();

        vector<int> neighbours = grafo[node];
        for(const auto& n : neighbours){
          if(!visited[n]){
            fila.push(n);
            visited[n] = true;
            total++;
          }
        }
      }
    }
    if(total < menor){
      menor = total;
    }
  }

  cout << menor << endl;

  // for (size_t i = 0; i < h; i++) {
  //   for (size_t j = 0; j < l; j++) {
  //     cout << (i*l+j) << ":   ";
  //     for (vector<int>::const_iterator k = grafo[i*l+j].begin(); k != grafo[i*l+j].end(); ++k)
  //       cout << *k << ' ';
  //     cout << endl;
  //   }
  // }


  return 0;
}
