#include <bits/stdc++.h>
#include <iostream>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int impar(int a){
  if(a%2==0) return a-1;
  return a;
}

int main(){_;
  int n;
  cin >> n;
  int h[n];

  for (size_t i = 0; i < n; i++)
    cin >> h[i];

  int maior = -1;
  for (int i = 0; i < n; i++) {
    int altura = -1;
    for (int j = impar(n); j > 0; j -= 2) {
      bool possivel = true;
      for (int k = 0; k < ceil(j/2); k++) {
        if(h[i+k] < k+1 && h[j-k-1] < k+1){
          possivel = false;
          break;
        }
      }
      if(possivel){
        altura = j;
        cout << altura << endl;
        break;
      }
    }
    maior = max(maior, altura);
  }

  cout << maior << endl;

  return 0;
}
