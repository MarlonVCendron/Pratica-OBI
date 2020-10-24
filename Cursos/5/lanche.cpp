#include <bits/stdc++.h>
#include <iostream>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

#define MAXS 260
#define INF 99999999

int s, c;
int mat[MAXS][MAXS];

int main(){_;
  cin >> s >> c;

  for (size_t i = 0; i < s; i++)
    for (size_t j = 0; j < s; j++)
      mat[i][j] = (i == j) ? 0 : INF;

  for (int a, b, d, i = 0; i < c; i++) {
    cin >> a >> b >> d;
    mat[a-1][b-1] = d;
    mat[b-1][a-1] = d;
  }

  for (size_t k = 0; k < s; k++)
    for (size_t i = 0; i < s; i++)
      for (size_t j = 0; j < s; j++)
        mat[i][j] = min(mat[i][j], mat[i][k]+mat[k][j]);

  int menor = INF;
  for (size_t i = 0; i < s; i++) {
    int maior = 0;
    for (size_t j = 0; j < s; j++) {
      maior = max(maior, mat[i][j]);
    }
    menor = min(menor, maior);
  }

  cout << menor << endl;

  return 0;
}
