#include <iostream>
#include <math.h>
using namespace std;

int main(){
  int k, x, y; cin >> k >> x >> y;

  cout << ((abs(x-y) >= k) ? "EH SUFICIENTE" : "NAO EH SUFICIENTE") << endl;
  return 0;
}
