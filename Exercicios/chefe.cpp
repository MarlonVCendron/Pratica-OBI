#include <bits/stdc++.h>
#include <iostream>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

#define MAXN 510

int n, m, p;
vector<int> g[MAXN];
int idade[MAXN];
int empregado[MAXN];

int main(){_;
  cin >> n >> m >> p;

  for (size_t i = 0; i < n; i++){
    cin >> idade[i];
    empregado[i] = i;
  }

  for (size_t i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    // Y é gerenciado por X
    g[y-1].push_back(x-1);
  }

  for (size_t i = 0; i < p; i++) {
    char o;
    int a;
    cin >> o >> a;

    if(o == 'T'){
      int b;
      cin >> b;
      empregado[empregado[a-1]] = b-1;
      empregado[empregado[b-1]] = a-1;
    }else{
      cout << "Gerentes de " << a << ": " << endl;
      for(auto const &x : g[empregado[a-1]]){
        cout << empregado[x]+1 << " ";
      }
      cout << endl;
    }
  }

  return 0;
}
