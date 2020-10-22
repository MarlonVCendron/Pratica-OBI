#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#include <iostream>
using namespace std;

int main(){_
  int m, n; cin >> m >> n;

  int dinheiro[n] = {};

  int compensado = 0;
  for (int x, v, y, i = 0; i < m; i++) {
    cin >> x >> v >> y;

    dinheiro[x-1] -= v;
    dinheiro[y-1] += v;

    compensado += v;
  }

  int total = 0;
  for (size_t i = 0; i < n; i++) {
    if(dinheiro[i] > 0) total += dinheiro[i];
  }

  cout << ((total < compensado) ? 'S' : 'N') << endl;
  cout << total << endl;

  return 0;
}
