#include <bits/stdc++.h>
#include <iostream>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

int n;

int main(){_;
  cin >> n;
  vector<pll> a;
  for (int x, h, i = 0; i < n; i++) {
    cin >> x >> h;
    a.push_back(pll(x, h));
  }

  sort(a.begin(), a.end());

  int total = 0, atual = 0;
  while(true){
    if(atual == n-1) break;

    for (int i = n-1; i >= atual; i--) {
      if(){ //pode ver a árvore
        atual = i;
        total++;
        break;
      }
    }
  }

  cout << total << endl;

  return 0;
}
