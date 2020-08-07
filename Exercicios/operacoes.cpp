#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
  char op;
  cin >> op;
  double a, b;
  cin >> a >> b;

  printf("%.2f\n", (op == 'M') ? a*b : a/b);

  return 0;
}
