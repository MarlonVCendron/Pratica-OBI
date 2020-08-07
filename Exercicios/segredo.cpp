#include <iostream>
#include <math.h>
#include <array>
using namespace std;

#define MAXN 100010

int main(){
  int n, m;
  cin >> n >> m;
  int nums[MAXN], seq[MAXN];
  array<array<int, 10>, MAXN> sum;

  for (size_t i = 0; i < n; i++) {
    cin >> nums[i];
  }

  for (size_t i = 0; i < m; i++) {
    cin >> seq[i];
  }

  int total[10];
  for (size_t i = 0; i < 10; i++) {
    sum[0][i] = 0;
    total[i] = 0;
  }

  for (size_t i = 1; i <= n; i++) {
    sum[i] = sum[i-1];
    sum[i][nums[i-1]] += 1;
  }



  for (size_t i = 1; i < m; i++) {
    int tmp[10];
    int curr = seq[i];
    int prev = seq[i-1];

    if (i == 1) prev--;

    if(prev > curr){
      curr--;
      prev --;
    }

    for (size_t j = 0; j < 10; j++) {
      tmp[j] = abs(sum[curr][j] - sum[prev][j]);
      total[j] += tmp[j];
    }

    // for (size_t k = 0; k < 10; k++) {
    //   cout << total[k] << ' ';
    // }
    // cout << endl;

  }

  for (size_t k = 0; k < 10; k++) {
    cout << total[k] << ' ';
  }
  cout << endl;

  return 0;
}
