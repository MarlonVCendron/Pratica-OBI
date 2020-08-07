#include <iostream>
#include <set>
using namespace std;

int main(){
  int n; cin >> n;
  int tmp;
  set<int> nums;

  int total = 0;

  for (size_t i = 0; i < n; i++) {
    cin >> tmp;

    if(nums.find(tmp) == nums.end()){
      nums.insert(tmp);
      total++;
    }
  }

  cout << total << endl;

  return 0;
}
