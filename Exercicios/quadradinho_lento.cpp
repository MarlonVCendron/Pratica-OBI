#include <iostream>
using namespace std;

int main(){
  int n; cin >> n;
  int nums[n];

  for (size_t i = 0; i < n; i++) {
    cin >> nums[i];
  }

  int total = 0;
  for (size_t i = 0; i < n; i++) {
    int soma = 0;

    for (size_t j = i; j < n; j++) {
      soma += nums[j];
      if (soma % 8 == 0) total++;
    }
  }

  cout << total << endl;
  
  return 0;
}
