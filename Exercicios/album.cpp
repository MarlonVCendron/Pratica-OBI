#include <iostream>
using namespace std;

int main(){
  int x, y, a, b, c, d;
  cin >> x >> y >> a >> b >> c >> d;

  int sx1 = x - a;
  int sy1 = y - b;

  int sx2 = x - b;
  int sy2 = y - a;

  if(sx1 >= 0 && sy1 >= 0){
    if(
      (c <= sx1 && d <= y) ||
      (c <= sy1 && d <= x) ||
      (d <= sx1 && c <= y) ||
      (d <= sy1 && c <= x)
    ){
      cout << 'S' << endl;
      return 0;
    }
  }

  if(sx2 >= 0 && sy2 >= 0){
    if(
      (c <= sx2 && d <= y) ||
      (c <= sy2 && d <= x) ||
      (d <= sx2 && c <= y) ||
      (d <= sy2 && c <= x)
    ){
      cout << 'S' << endl;
      return 0;
    }
  }

  cout << 'N' << endl;

  return 0;
}
