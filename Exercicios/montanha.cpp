#include <iostream>
using namespace std;

int main(){
  int n; cin >> n;
  int nums[n];

  for (size_t i = 0; i < n; i++) {
    cin >> nums[i];
  }

  for (size_t i = 1; i < n-1; i++) {
    if(nums[i-1] > nums[i] && nums[i+1] > nums[i]){
      cout << 'S' << endl;
      return 0;
    }
  }

  cout << 'N' << endl;
  return 0;
}
