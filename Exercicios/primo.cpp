#include <iostream>
#include <math.h>
using namespace std;

int main(){
  int n; cin >> n;

  if (n == 2) {
    cout << 'S' << endl;
    exit(0);
  }

  if(n % 2 == 0 || n == 1){
    cout << 'N' << endl;
    exit(0);
  }

  for (size_t i = 3; i <= (int)sqrt(n); i+=2) {
    if(n % i == 0){
      cout << 'N' << endl;
      exit(0);
    }
  }

  cout << 'S' << endl;
  return 0;
}
