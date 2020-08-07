#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, size;

int bfs(int& s, int& e, vector<int> *grafo){
  queue<int> q;
  q.push(s);

  bool visited[size];
  int prev[size];

  for (size_t i = 0; i < size; i++) {
    visited[i] = false;
    prev[i] = -1;
  }

  visited[s] = true;

  while (!q.empty()) {
    int node = q.front();
    q.pop();
    vector<int> neighbours = grafo[node];

    for(const auto& next: neighbours) {
      if(!visited[next]){
        q.push(next);
        visited[next] = true;
        prev[next] = node;
      }
    }
  }

  int d = 0;
  for (int i = e; i != -1; i = prev[i]) {
    d++;
  }

  return d;
}

int main(){
  cin >> n >> m;
  size = n*m;
  int s, e;

  int toca[n][m];
  vector<int> grafo[size];

  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < m; j++) {
      cin >> toca[i][j];
      if(toca[i][j] == 2) s = i*m+j;
      if(toca[i][j] == 3) e = i*m+j;
    }
  }

  int dr[] = {-1, 1, 0, 0};
  int dc[] = {0, 0, -1, 1};

  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < m; j++) {
      if(toca[i][j] == 0) continue;

      for (size_t k = 0; k < 4; k++) {
        int ii = i + dr[k];
        int jj = j + dc[k];

        if(ii < 0 || jj < 0) continue;
        if(ii >= n || jj >= m) continue;
        if(toca[ii][jj] == 0) continue;

        grafo[i*m+j].push_back(ii*m+jj);
      }
    }
  }

  cout << bfs(s, e, grafo) << endl;

  // for (size_t i = 0; i < n; i++) {
  //   for (size_t j = 0; j < m; j++) {
  //     cout << (i*m+j) << ":   ";
  //     for (vector<int>::const_iterator k = grafo[i*m+j].begin(); k != grafo[i*m+j].end(); ++k)
  //       cout << *k << ' ';
  //     cout << endl;
  //   }
  // }


  return 0;
}
