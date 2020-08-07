#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
  int n; cin >> n;
  float p, g, custo;

  float min = 100010;
  for (size_t i = 0; i < n; i++) {
    cin >> p >> g;

    custo = p/g;
    if(custo < min) min = custo;
  }

  printf("%.2f\n", min*1000);

  return 0;
}
