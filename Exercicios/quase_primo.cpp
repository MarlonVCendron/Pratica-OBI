#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  int n, k;
  cin >> n >> k;

  int nums[k];
  for (size_t i = 0; i < k; ++i){
    cin >> nums[i];
  }

  int quase_primos = 0;

  for (size_t i = n; i > 0; i--) {
    int divide = 0;
    for (size_t j = 0; j < k; j++) {
      if(i % nums[j] == 0){
        divide = 1;
        break;
      }
    }

    if(!divide){
      quase_primos++;
    }
  }

  cout << quase_primos << endl;

  return 0;
}
