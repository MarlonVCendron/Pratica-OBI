#include <iostream>
using namespace std;

long unsigned int fatorial(long unsigned int n){
  if(n <= 1) return 1;
  else return n * fatorial(n-1);
}

int main(){
  long unsigned int n;
  cin >> n;

  cout << fatorial(n) << endl;
  return 0;
}
