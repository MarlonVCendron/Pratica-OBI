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
    for (int i = n-1; i >= 0; i--) {
      nums.push_back(tmp[i] - '0');
    }

    for (size_t i = 0; i < d; i++) {

      for (size_t j = 0; j <= 9; j++) {

      }
    }

    // for (size_t i = 0; i < nums.size(); i++) {
    //   cout << nums.top();
    // }

    cout << endl;
  }

  return 0;
}
