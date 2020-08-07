#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main(int argc, char const *argv[]) {
  int x;
  cin >> x;

  double nums[x];
  for (size_t i = 0; i < x; i++) {
    cin >> nums[i];
    // cout << pow(nums[i], 1.0/2) << endl;
    printf("%.4f\n", pow(nums[i], 1.0/2));
  }

  return 0;
}
