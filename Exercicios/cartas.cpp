#include <bits/stdc++.h>
#include <iostream>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int main(){_;
  int a, b, c; cin >> a >> b >> c;

  if(a==b) cout << c << endl;
  else if(a==c) cout << b << endl;
  else cout << a << endl;
  
  return 0;
}
