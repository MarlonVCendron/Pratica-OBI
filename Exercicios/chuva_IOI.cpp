#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#include <bits/stdc++.h>
#include <iostream>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

#define MAXS 1010
#define MAXK 260
#define MAXQ 1000010

int n, m, k, q;
int alturas[MAXS][MAXS];
int coletores[MAXK][2];
int r[MAXQ][4];
vector<int> g[MAXS*MAXS];

int idx(int i, int j){
  return m*i+j;
}

int main(){_;
  cin >> n >> m >> k;
  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < m; j++) {
      cin >> alturas[i][j];
    }
  }
  for (size_t i = 0; i < k; i++) {
    cin >> coletores[i][0] >> coletores[i][1];
  }

  cin >> q;
  for (size_t i = 0; i < q; i++) {
    cin >> r[i][0] >> r[i][1] >> r[i][2] >> r[i][3];
  }

  // CÓDIGO //

  // Montar o grafo
  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < m; j++) {
      int di[] = {1, -1, 0, 0};
      int dj[] = {0, 0, 1, -1};

      for (size_t k = 0; k < 4; k++) {
        int ii = i + di[k];
        int jj = j + dj[k];

        if(ii < 0 || jj < 0 || ii >= n || jj >= m) continue;

        if(alturas[ii][jj] <= alturas[i][j]){
          g[idx(i,j)].push_back(idx(ii,jj));
        }
      }
    }
  }

  // for (size_t i = 0; i < n*m; i++) {
  //   cout << i  << ": ";
  //   for (auto const &x : g[i]) {
  //     cout << x << " ";
  //   }
  //   cout << endl;
  // }

  for (size_t z = 0; z < q; z++) {
    // for (size_t i = r[z][0]; i <= r[z][2]; i++) {
    //   for (size_t j = r[z][1]; j <= r[z][3]; j++) {
    //
    //   }
    // }

    int is = r[z][0];
    int js = r[z][1];
    int ie = r[z][2];
    int je = r[z][3];

    int chuva[n][m] = {};
    int visitado[n][m] = {};

    for (size_t i = 0; i < n; i++) {
      for (size_t j = 0; j < m; j++) {
        if(i >= is && i <= ie && j >= js && j <= je){
          chuva[i][j] = 1;
        }
      }
    }

    for (size_t i = 0; i < n; i++) {
      for (size_t j = 0; j < m; j++) {
        if(visitado[i][j]) continue;
        if(chuva[i][j]){
          queue<int> fila;
          fila.push(idx(i,j));
          visitado[i][j] = 1;

          while (!fila.empty()) {
            int index = fila.top();
            fila.pop();

            for(auto const &x : g[index]){
              
            }
          }
        }
      }
    }

  }

  return 0;
}
