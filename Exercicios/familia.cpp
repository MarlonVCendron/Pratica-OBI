#include <iostream>
using namespace std;

#define MAXN 50100

int n, m;
int pai[MAXN];

int find(int a){
  if (pai[a] == a) return a;
  return pai[a] = find(pai[a]);
}

void join(int a, int b){
  int paiA = find(a);
  int paiB = find(b);

  if (paiA < paiB) pai[paiB] = paiA;
  else pai[paiA] = paiB;
}

int main(){
  cin >> n >> m;

  int soma[n+1];

  for (size_t i = 1; i <= n; i++){
    pai[i] = i;
    soma[i] = 0;
  }

  for (int a, b, i = 0; i < m; i++) {
    cin >> a >> b;

    join(a, b);
  }

  int total = 0;
  for (size_t i = 1; i <= n; i++) {
    if(pai[i] == i) total++;
  }

  cout << total << endl;

  return 0;
}
