#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  int campo[n], minas[n];
  for (size_t i = 0; i < n; i++) {
    cin >> campo[i];
    minas[i] = 0;
  }

  minas[0] = campo[0] + campo[1];
  minas[n-1] = campo[n-1] + campo[n-2];

  for (size_t i = 1; i < n-1; i++) {
    minas[i] = campo[i-1] + campo[i] + campo[i+1];
  }

  for (size_t i = 0; i < n; i++) {
    cout << minas[i] << endl;
  }
  return 0;
}
