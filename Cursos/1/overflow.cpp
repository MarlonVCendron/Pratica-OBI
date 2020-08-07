#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  int n, p, q, r;
  char c;
  cin >> n;
  cin >> p >> c >> q;

  if(c == '+'){
    r = p + q;
  }else{
    r = p * q;
  }

  if(r > n){
    cout << "OVERFLOW" << endl;
  }else{
    cout << "OK" << endl;
  }

  return 0;
}
