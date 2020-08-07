#include <iostream>
using namespace std;

#define MAX 100010

int n, m, pontos[MAX], pai[MAX];

int find(int x){
  if(pai[x] == x) return x;
  return pai[x] = find(pai[x]);
}

void join(int x, int y){
  int a = find(x);
  int b = find(y);

  if (a == b) return;

  pai[a] = b;

  pontos[b] += pontos[a];
}

int main(){
  while (true) {
    cin >> n >> m;

    if(n == 0) break;

    for (size_t i = 1; i <= n; i++) {
      cin >> pontos[i];
      pai[i] = i;
    }

    int q, a, b, total = 0;
    for (size_t i = 0; i < m; i++) {
      cin >> q >> a >> b;

      if (q == 1) {
        join(a, b);
      }else{
        int paiA = find(a);
        int paiB = find(b);
        if(paiA == find(1)){
          if (pontos[paiA] > pontos[paiB]) total++;
        }else if(paiB == find(1)){
          if (pontos[paiB] > pontos[paiA]) total++;
        }
      }
    }

    cout << total << endl;

    // for (size_t i = 1; i <= n; i++) {
    //   cout << pontos[i] << "  ";
    // }
    // cout << endl;
  }

  return 0;
}
