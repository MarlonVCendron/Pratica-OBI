#include <iostream>
using namespace std;

int main(){
  int n;
  cin >> n;
  int moedas[] = {100, 50, 25, 10, 5, 1};
  int total = 0;
  while (n != 0) {
    for (size_t i = 0; i < 6; i++) {
      if (n - moedas[i] >= 0){
        n -= moedas[i];
        total++;
        break;
      }
    }
  }

  cout << total << endl;

  return 0;
}
