#include <bits/stdc++.h>
#include <iostream>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

typedef pair<int, int> pii;

int n, q;
map<pii, int> mat;

void changeRow(int r, int v){
  for (size_t i = 0; i < n; i++) mat[pii(r,i)] = v;
}

void changeColumn(int r, int v){
  for (size_t i = 0; i < n; i++) mat[pii(i,r)] = v;
}

int main(){_;
  cin >> n >> q;

  for (int op, x, i = 0; i < q; i++) {
    cin >> op >> x;
    --x;

    if(op <= 2){
      int r; cin >> r;

      if(op == 1) changeRow(x, r);
      else changeColumn(x, r);
    }else{
      map<int, int> m;
      int maxNum, maxV = -1;

      if(op == 3){
        for (size_t i = 0; i < n; i++) m[mat[pii(x,i)]]++;
      }else{
        for (size_t i = 0; i < n; i++) m[mat[pii(i,x)]]++;
      }

      for(auto it = m.begin(); it != m.end(); it++){
        if(it->second >= maxV){
          maxV = it->second;
          maxNum = it->first;
        }
      }
      cout << maxNum << endl;
    }
  }

  return 0;
}
