#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  int n, l, c;
  cin >> n;
  int total = 0;

  for (size_t i = 0; i < n; i++) {
    cin >> l >> c;
    if (l > c){
      total += c;
    }
  }

  cout << total << endl;

  return 0;
}
