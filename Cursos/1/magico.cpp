#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int m[n][n];
  int x = 0;
  int diagSec = 0;
  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < n; j++) {
      cin >> m[i][j];
      if (i == j) {
        x += m[i][j];
      }
      if(i == n-1-j){
        diagSec+= m[i][j];
      }
    }
  }

  if (diagSec != x) {
    cout << -1 << endl;
    return 0;
  }

  for (size_t i = 0; i < n; i++) {
    int soma = 0;
    for (size_t j = 0; j < n; j++) {
      soma += m[i][j];
    }
    if(soma != x){
      cout << -1 << endl;
      return 0;
    }
  }

  for (size_t i = 0; i < n; i++) {
    int soma = 0;
    for (size_t j = 0; j < n; j++) {
      soma += m[j][i];
    }
    if(soma != x){
      cout << -1 << endl;
      return 0;
    }
  }

  cout << x << endl;

  return 0;
}
