#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, m, x;
  cin >> n;
  vector<int> fila;

  for (size_t i = 0; i < n; i++) {
    cin >> x;
    fila.push_back(x);
  }

  cin >> m;
  for (size_t i = 0; i < m; i++) {
    cin >> x;
    fila.erase(remove(fila.begin(), fila.end(), x), fila.end());
  }

  for(const auto& v: fila){
    cout << v << " ";
  }

  cout << endl;

  return 0;
}
