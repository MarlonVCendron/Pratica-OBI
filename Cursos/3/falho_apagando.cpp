#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
  int n, d;

  while (true) {
    cin >> n >> d;
    if (n == 0) break;

    string tmp;
    vector<int> nums;

    cin >> tmp;
    for (size_t i = 0; i < n; i++) {
      nums.push_back(tmp[i] - '0');
    }

    for (size_t k = 0; k < d; k++) {
      int min = 100100;
      int minIndex;

      for (size_t i = 0; i < nums.size(); i++) {
        if (nums[i] < min) {
          min = nums[i];
          minIndex = i;
        }
      }

      // cout << min << endl;
      nums.erase(nums.begin()+minIndex);
    }

    for (size_t i = 0; i < nums.size(); i++) {
      cout << nums[i];
    }

    cout << endl;
  }

  return 0;
}
