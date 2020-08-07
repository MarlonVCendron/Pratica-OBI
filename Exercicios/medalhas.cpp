#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[]) {
  int nadadores[3], maior = 0, menor = 1000, a, b, c;

  for (size_t i = 0; i < 3; i++) {
    cin >> nadadores[i];
    maior = max(maior, nadadores[i]);
    menor = min(menor, nadadores[i]);
  }

  for (size_t i = 0; i < 3; i++) {
    if(nadadores[i] == menor){
      a = i+1;
    }else if(nadadores[i] == maior){
      c = i+1;
    }else{
      b = i+1;
    }
  }

  cout << a << endl;
  cout << b << endl;
  cout << c << endl;


  return 0;
}
