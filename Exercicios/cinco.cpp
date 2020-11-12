#include <bits/stdc++.h>
#include <iostream>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int main(){_;
  int n; cin >> n;
  int d[n];

  for (short int i = 0; i < n; i++) cin >> d[i];

  int l = d[n-1];
  bool greater = l > 5;
  bool swapped = false;
  for (int i = 0; i < n; i++) {
    if(d[i] == 0 || (d[i] == 5 && greater)){
      swapped = true;
      d[n-1] = d[i];
      d[i] = l;
      break;
    }
  }

  if(!swapped){
    for (int i = n-1; i >= 0; i--) {
      if(d[i] == 5){
        swapped = true;
        d[n-1] = d[i];
        d[i] = l;
        break;
      }
    }
  }

  if(!swapped){
    cout << -1 << endl;
    return 0;
  }

  for (short int i = 0; i < n; i++) cout << d[i] << " ";
  cout << endl;
  return 0;
}
