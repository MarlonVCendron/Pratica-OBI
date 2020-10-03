#include <iostream>
using namespace std;

int main(){
  int a, b, c, d; cin >> a >> b >> c >> d;

  int maior = max(a, max(b, max(c, d))) + min(a, min(b, min(c, d)));
  cout << abs(maior - ((a+b+c+d) - maior)) << endl;
  return 0;
}
