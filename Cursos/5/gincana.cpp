#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
  int n, m, p, q;
  cin >> n >> m;
  vector<int> grafo[n];

  for (size_t i = 0; i < m; i++) {
    cin >> p >> q;
    grafo[p-1].push_back(q-1);
    grafo[q-1].push_back(p-1);
  }

  bool visited[n];
  for (size_t i = 0; i < n; i++) {
    visited[i] = false;
  }

  int total = 0;

  for (size_t i = 0; i < n; i++) {
    if(!visited[i]){
      queue<int> q;
      q.push(i);

      while (!q.empty()) {
        int node = q.front();
        q.pop();

        vector<int> neighbours = grafo[node];

        for(const auto& next: neighbours) {
          if(!visited[next]){
            visited[next] = true;
            q.push(next);
          }
        }
      }

      total++;
    }
  }

  cout << total << endl;

  return 0;
}
