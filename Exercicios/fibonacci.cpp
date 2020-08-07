#include <iostream>
using namespace std;

int main(){
  int n; cin >> n;
  int fib[n];

  fib[0] = 0;
  fib[1] = 1;

  if (n >= 1) cout << 0 << ' ';
  if (n >= 2) cout << 1 << ' ';

  for (size_t i = 2; i < n; i++) {
    fib[i] = fib[i-1] + fib[i-2];
    cout << fib[i] << ' ';
  }

  cout << endl;

  return 0;
}
