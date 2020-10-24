#include <bits/stdc++.h>
#include <iostream>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int main(){_;
  int n; cin >> n;
  int notas[n];
  map<int, size_t> freq;

  for (size_t i = 0; i < n; i++) {
    cin >> notas[i];
    freq[notas[i]]++;
  }

  int maxNota, max = 0;
  for (auto it = freq.begin(); it != freq.end(); it++) {
    if(it->second >= max){
      max = it->second;
      maxNota = it->first;
    }
  }

  cout << maxNota << endl;

  return 0;
}
