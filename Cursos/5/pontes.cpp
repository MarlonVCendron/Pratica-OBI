#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pii;
#define MAX 1010
#define INF 99999999

int n, m;
vector<pii> pontes[MAX];

int dijkstra(){
  int N = n+2;
  bool visited[N];
  int dist[N];

  for (size_t i = 0; i < N; i++) {
    visited[i] = false;
    dist[i] = INF;
  }
  dist[0] = 0;

  priority_queue< pii, vector<pii>, greater<pii> > fila;
  fila.push(pii(0,0));

  while (!fila.empty()) {
    int minValue = fila.top().first;
    int index = fila.top().second;
    fila.pop();
    visited[index] = true;

    if(dist[index] < minValue) continue;

    for(const auto& v : pontes[index]){
      if(visited[v.second]) continue;
      int newDist = dist[index] + v.first;
      if(newDist < dist[v.second]){
        dist[v.second] = newDist;
        fila.push(pii(newDist, v.second));
      }
    }
  }

  return dist[N-1];
}

int main(){
  cin >> n >> m;
  int s, t, b;

  for (size_t i = 0; i < m; i++) {
    cin >> s >> t >> b;
    pontes[s].push_back(pii(b, t));
    pontes[t].push_back(pii(b, s));
  }

  cout << dijkstra() << endl;

  // for (size_t i = 0; i < n; i++) {
  //   cout << i << ":  ";
  //   for(const auto& v: pontes[i]){
  //     cout << "(" << v.first << " "<< v.second << ")  ";
  //   }
  //   cout << endl;
  // }

  return 0;
}
