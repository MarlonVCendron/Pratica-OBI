#include <iostream>
using namespace std;

long int gcd(long int a, long int b){
  if(b == 0){
    return a;
  }else{
    return gcd(b, a % b);
  }
}

int main() {
  long int n, m;
  cin >> n >> m;

  for (long int i = m; i > 0; i--) {
    if(gcd(n, i) == 1){
      cout << i << endl;
      break;
    }
  }

  return 0;
}
