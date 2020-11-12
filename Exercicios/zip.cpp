#include <bits/stdc++.h>
#include <iostream>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int pontos(int a, int b){
  if(a == b) return 4*a;
  if(a == b-1 || a == b+1) return 3*(a+b);
  return a+b;
}

int main(){_;
  int l1, l2, c1, c2;
  cin >> l1 >> l2 >> c1 >> c2;

  int pl = pontos(l1, l2);
  int pc = pontos(c1, c2);

  if(pl > pc) cout << "Lia" << endl;
  else if(pl < pc) cout << "Carolina" << endl;
  else cout << "empate" << endl;
  return 0;
}
