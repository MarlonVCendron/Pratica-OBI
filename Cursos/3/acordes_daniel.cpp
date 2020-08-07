#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define MAXN (int)100010
#define F first
#define S second

struct SegTree{
		#define NSEG MAXN
		#define mid(x, y) (x + (y - x)/2)
		#define L(x) (x<<1)
		#define R(x) ((x<<1)+1)

		typedef int Node;

		int n;
		int ansq[9], aux[9], lazy[4*NSEG];
		Node t[4*NSEG][9];

		void upLazy(int node, int l, int r) {
			if (lazy[node]) {
				int value = lazy[node];
				lazy[node] = 0;
				memset(aux, 0, sizeof(aux));
				for (int i = 0; i < 9; i++)
					aux[(i+value)%9] = t[node][i];
				for (int i = 0; i < 9; i++)
					t[node][i] = aux[i];

				if (l != r) {
					lazy[L(node)] += value;
					lazy[R(node)] += value;
				}
			}
		}

		void build(int node, int l, int r) {
			lazy[node] = 0;
			if (l == r) {
				t[node][1] = 1;
			} else {
				build(L(node), l, mid(l, r));
				build(R(node), mid(l, r)+1, r);
				t[node][1] = t[L(node)][1] + t[R(node)][1];
			}
		}

		void update(int node, int l, int r, int a, int b, int value) {
			upLazy(node, l, r);
			if (r < l || b < l || r < a) return;
			if (a <= l && r <= b) {
				lazy[node] = value;
				upLazy(node, l, r);
			} else {
				update(L(node), l, mid(l, r), a, b, value);
				update(R(node), mid(l, r)+1, r, a, b, value);
				for (int i = 0; i < 9; i++) {
					t[node][i] = t[L(node)][i] + t[R(node)][i];
				}
			}
		}

		void query(int node, int l, int r, int a, int b) {
			upLazy(node, l, r);
			if (b < l || r < a) return;
			if (a <= l && r <= b) {
				for (int i = 0; i < 9; i++) {
					ansq[i] += t[node][i];
				}
			} else {
				query(L(node), l, mid(l, r), a, b);
				query(R(node), mid(l, r)+1, r, a, b);
			}
		}

		void build(int _n) {
			n = _n;
			build(1, 1, n);
		}
		void update(int a, int b, int value) {
			update(1, 1, n, a, b, value);
		}
		void query(int a, int b) {
			query(1, 1, n, a, b);
		}
};

int n, q;
SegTree st;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> q;
	st.build(n);

	for (int i = 1; i <= q; i++) {
		memset(st.ansq, 0, sizeof(st.ansq));

		int a, b;
		cin >> a >> b;
		st.query(a+1, b+1);

		int mx=-1, ind;
		for (int j = 0; j < 9; j++) {
			if (st.ansq[j] >= mx) {
				mx = st.ansq[j];
				ind = j;
			}
		}
		st.update(a+1, b+1, ind);
	}

	for (int i = 1; i <= n; i++) {
		memset(st.ansq, 0, sizeof(st.ansq));
		st.query(i, i);

		for (int j = 0; j < 9; j++) {
			if (st.ansq[j]) {
				cout << j << endl;
			}
		}
	}

	return 0;
}
