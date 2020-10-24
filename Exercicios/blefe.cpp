#include <bits/stdc++.h>
#include <iostream>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int main(){_;
  int n, m; cin >> n >> m;
  int b[m];
  set<int> a;

  for (int tmp, i = 0; i < n; i++) {
    cin >> tmp;
    a.insert(tmp);
  }

  for (size_t i = 0; i < m; i++) {
    cin >> b[i];
  }

  // 40 pontos apenas. Tempo limite.
  for (size_t i = 0; i < m; i++) {
    if(a.find(b[i]) == a.end()){
      cout << b[i] << endl;
      return 0;
    }

    for (size_t j = 0; j <= i; j++) {
      a.insert(b[i] + b[j]);
    }
  }

  cout << "sim" << endl;

  return 0;
}
