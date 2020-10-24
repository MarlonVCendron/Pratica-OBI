#include <bits/stdc++.h>
#include <iostream>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

#define MAXN 100010

int n;
int nums[MAXN];

int mdc(int a, int b){
  return (b == 0) ? a : mdc(b, a%b);
}

int mdc_sequenciado(int i){
  if(i == n-2) return mdc(nums[i], nums[i+1]);
  return mdc(nums[i], mdc_sequenciado(i+1));
}

int main(){_;
  cin >> n;

  for (size_t i = 0; i < n; i++) {
    cin >> nums[i];
  }

  cout << mdc_sequenciado(0) << endl;

  return 0;
}
