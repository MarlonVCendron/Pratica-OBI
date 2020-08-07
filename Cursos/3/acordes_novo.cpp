#include <iostream>
#include <string.h>
using namespace std;

#define MAXN (int)100010

struct SegTree{
  #define mid(x, y) ((x+y)/2)
  #define L(x) (x<<1)
  #define R(x) ((x<<1) + 1)

  int n;
  int ansq[9], aux[9], lazy[4*MAXN];
  int tree[4*MAXN][9];

  void upLazy(int node, int l, int r){
    if(lazy[node]){
      int value = lazy[node];
      lazy[node] = 0;
      memset(aux, 0, sizeof(aux));

			for (int i = 0; i < 9; i++)
				aux[(i+value)%9] = tree[node][i];
			for (int i = 0; i < 9; i++)
				tree[node][i] = aux[i];

      if(l != r){
        lazy[L(node)] += value;
        lazy[R(node)] += value;
      }
    }
  }

  void build(int node, int l, int r) {
    lazy[node] = 0;
    if(l == r){
      tree[node][1] = 1;
    }else{
      build(L(node), l, mid(l, r));
      build(R(node), mid(l, r)+1, r);
      tree[node][1] = tree[L(node)][1] + tree[R(node)][1];
    }
  }

  void query(int node, int l, int r, int a, int b) {
    upLazy(node, l, r);
    if(b < l || a > r) return;
    if(a <= l && b >= r) {
      for (size_t i = 0; i < 9; i++) {
        ansq[i] += tree[node][i];
      }
    }else{
      query(L(node), l, mid(l, r), a, b);
      query(R(node), mid(l, r)+1, r, a, b);
    }
  }

  void update(int node, int l, int r, int a, int b, int value){
    upLazy(node, l, r);
    if(b < l || a > r) return;
    if(a <= l && b >= r){
      lazy[node] = value;
      upLazy(node, l, r);
    }else{
			update(L(node), l, mid(l, r), a, b, value);
			update(R(node), mid(l, r)+1, r, a, b, value);
			for (int i = 0; i < 9; i++) {
				tree[node][i] = tree[L(node)][i] + tree[R(node)][i];
			}
    }
  }

  void build(int _n){
    n = _n;
    build(1, 1, n);
  }

  void query(int a, int b){
    query(1, 1, n, a, b);
  }

  void update(int a, int b, int value){
    update(1, 1, n, a, b, value);
  }

  void print(){
    for (size_t i = 0; i < 4*n; i++) {
      cout << i << ":   ";
      for (size_t j = 0; j < 9; j++) {
        cout << tree[i][j] << " ";
      }
      cout << endl;
    }
  }
};

int n, q;
struct SegTree t;

int main(){
  cin >> n >> q;
  t.build(n);

  for (size_t i = 0; i < q; i++) {
    int a, b;
    cin >> a >> b;

    memset(t.ansq, 0, sizeof(t.ansq));

    t.query(a+1, b+1);

    int max = -1, idx;
    for (size_t j = 0; j < 9; j++) {
      if(t.ansq[j] >= max){
        max = t.ansq[j];
        idx = j;
      }
    }

    t.update(a+1, b+1, idx);
  }

	for (int i = 1; i <= n; i++) {
		memset(t.ansq, 0, sizeof(t.ansq));
		t.query(i, i);

		for (int j = 0; j < 9; j++) {
			if (t.ansq[j]) {
				cout << j << endl;
			}
		}
	}

  return 0;
}
