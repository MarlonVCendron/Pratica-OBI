#include <bits/stdc++.h>
#include <iostream>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int main(){_;
  int a1, d1, a2, d2; cin >> a1 >> d1 >> a2 >> d2;

  if(d1 == a2 && d2 != a1) cout << 1 << endl;
  else if(d2 == a1 && d1 != a2) cout << 2 << endl;
  else cout << -1 << endl;

  return 0;
}
