#include <iostream>
#include <vector>
using namespace std;

int main(){
  unsigned int n; cin >> n;
  vector<int> nums;
  int tmp;
  long long int total = 1;

  for (size_t i = 0; i < n; i++) {
    cin >> tmp;
    nums.push_back(tmp);
  }

  for (size_t i = 0; i < 3; i++) {
    int maior = -10000000, indexMaior;
    for (int j=0; j < nums.size(); j++) {
      if(nums[j] > maior){
        maior = nums[j];
        indexMaior = j;
      }
    }

    total *= maior;
    nums.erase(nums.begin() + indexMaior);
  }

  cout << total << endl;

  return 0;
}
