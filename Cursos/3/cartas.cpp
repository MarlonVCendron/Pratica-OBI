#include <iostream>
#include <set>
using namespace std;

int main(){
  int a, b; cin >> a >> b;
  int tmp;

  set<int> cartasA, cartasB;

  for (size_t i = 0; i < a; i++) {
    cin >> tmp;
    cartasA.insert(tmp);
  }

  for (size_t i = 0; i < b; i++) {
    cin >> tmp;
    cartasB.insert(tmp);
  }

  int totalA = 0, totalB = 0;

  for (set<int>::iterator it = cartasA.begin(); it != cartasA.end(); it++) {
    if (cartasB.find(*it) == cartasB.end()) {
      totalA++;
    }
  }

  for (set<int>::iterator it = cartasB.begin(); it != cartasB.end(); it++) {
    if (cartasA.find(*it) == cartasA.end()) {
      totalB++;
    }
  }

  cout << min(totalA, totalB) << endl;

  return 0;
}
