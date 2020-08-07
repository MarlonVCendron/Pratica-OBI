#include <iostream>
using namespace std;

int main(){
  int a, b, c, h, l; cin >> a >> b >> c >> h >> l;
  int m, n;

  if (a >= b && a >= c) {
    m = b;
    n = c;
  }else if (b >= a && b >= c) {
    m = a;
    n = c;
  }else{
    m = a;
    n = b;
  }

  if((m <= h && n <= l) || (n <= h && m <= l)){
    cout << 'S' << endl;
  }else{
    cout << 'N' << endl;
  }

  return 0;
}
