#include <iostream>
using namespace std;

int main(){
  int x, y; cin >> x >> y;
  int s = max(x, y);
  int num1[s], num2[s], result[s];

  for (size_t i = 0; i < s; i++) {
    num1[i] = 0;
    num2[i] = 0;
  }

  for (size_t i = 0; i < x; i++) cin >> num1[i];
  for (size_t i = 0; i < y; i++) cin >> num2[i];

  int rem = 0;
  for (int i = s-1; i >= 0; i--) {
    int sum = num1[i] + num2[i] + rem;
    result[i] = sum % 2;
    rem = sum / 2;
  }

  // if(rem) cout << "1 ";
  
  for (size_t i = 0; i < s; i++) cout << result[i] << ' ';

  cout << endl;
  return 0;
}
