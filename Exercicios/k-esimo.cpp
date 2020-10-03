#include <iostream>
#include <math.h>
using namespace std;

int main(){
  int a, b, n, k; cin >> a >> b >> n >> k;

  float x = pow(a + sqrt(b), n) / pow(10, k-1);
  // float x = a + sqrt(b);

  int y = (int) floor(x);

  cout << y % 10 << endl;
  return 0;
}
