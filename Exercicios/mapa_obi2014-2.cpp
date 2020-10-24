#include <bits/stdc++.h>
#include <iostream>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

typedef pair<int, int> pii;
#define MAXN 100010
#define F first
#define S second

long long int n;
long long int parent[MAXN];
map<int, int> size;

int find(int a){
  if(parent[a] == a) return a;
  else return parent[a] = find(parent[a]);
}

void join(int a, int b){
  int pa = find(a);
  int pb = find(b);

  parent[pb] = pa;

  size[pa] += size[pb]+1;
}

int main(){_;
  cin >> n;
  long long int e = n * (n-1) / 2;

  for (size_t i = 0; i < n; i++) parent[i] = i;

  for (int a, b, c, i = 0; i < n-1; i++) {
    cin >> a >> b >> c;

    if(c == 0) join(a-1, b-1);
  }

  for (size_t i = 0; i < n; i++) {
    if(parent[i] == i){
      e -= size[i] * (size[i]+1) / 2;
    }
  }

  cout << e << endl;

  return 0;
}
