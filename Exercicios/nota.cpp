#include <iostream>
using namespace std;

int main(){
  int b, t; cin >> b >> t;
  int x = (b+t)/2;

  if (x > 80) cout << 1 << endl;
  else if (x < 80) cout << 2 << endl;
  else cout << 0 << endl;

  return 0;
}
