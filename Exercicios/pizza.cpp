// CÓDIGO RUIM, TÁ METADE ERRADO
#include <bits/stdc++.h>
#include <iostream>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int main(){_;
  int n; cin >> n;
  int fatias[n];

  for (size_t i = 0; i < n; i++) {
    cin >> fatias[i];
  }

  int maior = 0, resposta = 0, lastI = 0;
  for (size_t i = 0; i < 2*n; i++) {
    if(i%n == lastI && i != 0) break;

    if(maior+fatias[i%n] > 0){
      maior = maior+fatias[i%n];
    }else{
      maior = 0;
      lastI = i%n;
    }
    resposta = max(resposta, maior);
  }

  cout << resposta << endl;
  return 0;
}
