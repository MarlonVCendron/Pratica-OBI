#include <iostream>
#include <string>
using namespace std;

int main(){
  int n; cin >> n;

  int count[10];
  for (size_t i = 0; i < 10; i++) count[i] = 0;

  for (size_t i = 0; i < n; i++) {
    string num; cin >> num;

    for (auto const &c : num) {
      count[c-'0']++;
    }
  }

  for (size_t i = 0; i < 10; i++) {
    cout << i << " - " << count[i] << endl;
  }

  return 0;
}
