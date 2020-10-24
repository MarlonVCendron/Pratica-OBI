#include <bits/stdc++.h>
#include <iostream>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int main(){_;
  int n; cin >> n;
  int vidas[n];

  int maior = 0, resposta = 0;
  for (size_t i = 0; i < n; i++) {
    cin >> vidas[i];

    maior = max(0, maior+vidas[i]);
    resposta = max(resposta, maior);
  }

  cout << resposta << endl;
  return 0;
}
