#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  int nums[n];
  for (size_t i = 0; i < n; i++) {
    cin >> nums[i];
  }

  // bool ordenado = false;
  //
  // while (!ordenado){
  //   ordenado = true;
  //   for (size_t i = 0; i < n-2; i++) {
  //     if(nums[i] > nums[i+1]){
  //       ordenado = false;
  //       int tmp = nums[i];
  //       nums[i] = nums[i+1];
  //       nums[i+1] = tmp;
  //     }
  //   }
  // }

  sort(nums, nums+n);

  for (size_t i = 0; i < n; i++) {
    cout << nums[i] << " ";
  }

  cout << endl;

  return 0;
}
