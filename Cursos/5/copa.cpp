#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN 110
#define MAXS 100000

struct aresta{
  bool ferrovia;
  int dist;
  int x, y;
};

int n, f, r;
aresta g[MAXS];
int pai[MAXS];

bool comp(aresta a, aresta b){
  if(a.ferrovia == b.ferrovia) return a.dist < b.dist;
  return a.ferrovia;
}

int find(int x){
  if (pai[x-1] == x) return x;
  return pai[x-1] = find(pai[x-1]);
}

void join(int a, int b){
  a = find(a);
  b = find(b);

  pai[a-1] = b;
}

int main(){
  cin >> n >> f >> r;

  aresta tmp;
  int count = 0;
  for (size_t i = 0; i < f; i++) {
    cin >> tmp.x >> tmp.y >> tmp.dist;
    tmp.ferrovia = true;

    g[count] = tmp;
    count++;
  }

  for (size_t i = 0; i < r; i++) {
    cin >> tmp.x >> tmp.y >> tmp.dist;
    tmp.ferrovia = false;

    g[count] = tmp;
    count++;
  }

  sort(g, g+count, comp);

  for (size_t i = 0; i < count; i++) {
    pai[i] = i+1;
  }

  int total = 0;
  for (size_t i = 0; i < count; i++) {
    if(find(g[i].x) != find(g[i].y)){ // diferentes
      join(g[i].x, g[i].y);

      total += g[i].dist;
    }
  }

  cout << total << endl;

  // for (size_t i = 0; i < count; i++) {
  //   cout << g[i].x << " " << g[i].y << " (" << g[i].dist << ") " << g[i].ferrovia << endl;
  // }

  return 0;
}
