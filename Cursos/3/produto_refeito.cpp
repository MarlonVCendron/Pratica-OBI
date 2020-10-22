#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#include <bits/stdc++.h>
#include <iostream>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

#define MAXN 100010

int n, k;
int nums[MAXN];

struct SegTree{
  #define L(x) ((x<<1)+1)
  #define R(x) ((x<<1)+2)
  #define mid(x, y) ((l+r)/2)

  int n;
  int t[2*MAXN-1];

  void build(int node, int l, int r) {
    if(l == r){
      t[node] = nums[l];
    }else{
      build(L(node), l, mid(l,r));
      build(R(node), mid(l,r)+1, r);
      t[node] = t[L(node)] * t[R(node)];
    }
  }

  void update(int node, int l, int r, int changeNode, int value){
    if(l == r){
      t[node] = value;
      nums[changeNode] = value;
    }else{
      int m = mid(l, r);

      if(changeNode <= m) update(L(node), l, mid(l,r), changeNode, value);
      else update(R(node), mid(l,r)+1, r, changeNode, value);

      t[node] = t[L(node)] * t[R(node)];
    }
  }

  int query(int node, int l, int r, int a, int b){
    if(a <= l && b >= r) return t[node];
    else if(a > r || b < l) return 1;

    int m = mid(l, r);

    return query(L(node), l, mid(l, r), a, b) * query(R(node), mid(l, r)+1, r, a, b);
  }

  void build(int _n){
    n = _n;
    build(0, 0, n-1);
  }

  void update(int changeNode, int value){
    update(0, 0, n-1, changeNode, value);
  }

  int query(int a, int b){
    return query(0, 0, n-1, a, b);
  }
};

SegTree st;

int main(){_
  while(cin >> n >> k){
    for (int tmp, i = 0; i < n; i++) {
      cin >> tmp;
      nums[i] = (tmp > 0) - (tmp < 0);
    }

    st.build(n);

    char o;
    for (int a, b, i = 0; i < k; i++) {
      cin >> o >> a >> b;

      if(o == 'C'){
        st.update(a-1, (b > 0)-(b < 0));
      }else{
        int r = st.query(a-1, b-1);

        char txt;
        if (r > 0) txt = '+';
        else if (r < 0) txt = '-';
        else txt = '0';

        cout << txt;
      }
    }

    cout << endl;
  }

  return 0;
}
