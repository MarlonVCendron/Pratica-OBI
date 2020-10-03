#include <iostream>
#include <algorithm>
using namespace std;

struct aresta{
  int dist;
  int x, y;
};

#define MAXN 1010
#define MAXM 1300000

int n, m;
aresta g[MAXM];
int pai[MAXN], peso[MAXN];

bool comp(aresta a, aresta b){ return a.dist < b.dist; };

int find(int a){
  if (pai[a] == a) return a;
  return pai[a] = find(pai[a]);
}

void join(int a, int b){
  a = find(a);
  b = find(b);

  if(peso[a] < peso[b]) pai[a] = b;
  else if(peso[a] > peso[b]) pai[b] = a;
  else{
    pai[a] = b;
    peso[b]++;
  }
}

int main(){
  cin >> n >> m;
  for (size_t i = 1; i <= m; i++) cin >> g[i].x >> g[i].y >> g[i].dist;

  for (size_t i = 1; i <= n; i++){
    pai[i] = i;
    // peso[i] = 0;
  }

  sort(g+1, g+m+1, comp);

  int total = 0;
  for (size_t i = 1; i <= m; i++) {
    if(find(g[i].x) != find(g[i].y)){
      join(g[i].x, g[i].y);

      total += g[i].dist;
    }
  }

  cout << total << endl;

  return 0;
}
