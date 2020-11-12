#include <bits/stdc++.h>
#include <iostream>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int n, d, a;

int main(){_;
  cin >> n >> d >> a;

  if(d == a) cout << 0 << endl;
  else if(d > a) cout << (d-a) << endl;
  else cout << (n-a)+d << endl;

  return 0;
}
