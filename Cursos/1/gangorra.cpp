#include <iostream>
using namespace std;

int main(){
  int p1, c1, p2, c2;
  cin >> p1 >> c1 >> p2 >> c2;
  int o;

  if(p1*c1 < p2*c2){
    o = 1;
  }else if(p1*c1 > p2*c2){
    o = -1;
  }else{
    o = 0;
  }

  cout << o << endl;

  return 0;
}
