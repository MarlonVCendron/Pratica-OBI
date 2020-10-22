#include <bits/stdc++.h>
#include <iostream>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

struct rect{
  int tx;
  int ty;
  int bx;
  int by;
};

int main(){_;
  int n; cin >> n;
  rect r[n];

  for (int a, b, c, d, i = 0; i < n; i++) {
    cin >> a >> b >> c >> d;
    rect tmp;
    tmp.tx = a;
    tmp.ty = b;
    tmp.bx = c;
    tmp.by = d;
    r[i] = tmp;
  }

  int total = 0;
  for (size_t i = 0; i < n; i++) {
    rect fora = r[i];

    bool wifi = true;
    for (size_t j = 0; j < n; j++) {
      if(i == j) continue;

      rect dentro = r[j];

      if(dentro.tx > fora.tx && dentro.ty < fora.ty && dentro.bx < fora.bx && dentro.by > fora.by){
        wifi = false;
        break;
      }
    }

    if(wifi) total++;
  }

  cout << total << endl;

  return 0;
}
