#include <iostream>
using namespace std;

int main(){
  int n,a,b,c,d,e,f,g;
  cin >> n >> a >> b >> c >> d >> e >> f >> g;

  if (c+a+b-e-d-f == n-g) {
    cout << 'N' << endl;
  }else{
    cout << 'S' << endl;
  }
  return 0;
}
