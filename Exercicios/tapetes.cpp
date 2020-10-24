#include <bits/stdc++.h>
#include <iostream>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int main(){_;
  long long int l, n;
  cin >> l >> n;

  n--;
  cout << (l-n)*(l-n)+n << endl;

  return 0;
}
