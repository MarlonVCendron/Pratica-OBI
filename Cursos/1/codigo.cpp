#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  int nums[n];
  for (size_t i = 0; i < n; i++) {
    cin >> nums[i];
  }

  int total = 0;
  for (size_t i = 0; i < n-2; i++) {
    if (nums[i] == 1 && nums[i+1] == 0 && nums[i+2] == 0) {
      total++;
    }
  }

  cout << total << endl;

  return 0;
}
