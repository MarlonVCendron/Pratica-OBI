#include <bits/stdc++.h>
#include <iostream>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int n;

int main(){_;
  cin >> n;
  int mat[n][n];

  for (size_t i = 0; i < n; i++)
    for (size_t j = 0; j < n; j++)
      cin >> mat[i][j];

  for(int k = 1; k < n*2; k++) {
    for(int j = 1; j < k; j++) {
      int i = k - j;
      if(i < n && j < n) {
        int sum = mat[i-1][j-1] + mat[i-1][j] + mat[i][j-1];
        mat[i][j] = int(sum <= 1);
      }
    }
  }

  cout << mat[n-1][n-1] << endl;

  return 0;
}
