#include <iostream>
#include <vector>
#include <stdbool.h>
using namespace std;

#define MAXN 100010

int n;
vector<int> g[MAXN];
bool visited[MAXN];
int numConnections[MAXN];

int count(int node){

  visited[node] = true;
  vector<int> neighbors = g[node];

  if(neighbors.size() == 1 && visited[neighbors[0]]) return numConnections[node] = 1;

  for (const auto &neighbor : neighbors) {
    count(neighbor);
  }
}

int main(){
  cin >> n;

  for (size_t i = 0; i < n; i++) {
    int a, b; cin >> a >> b;

    g[a-1].push_back(b-1);
    g[b-1].push_back(a-1);

    visited[i] = false;
  }

  // ???
  int result = count(0);

  return 0;
}
