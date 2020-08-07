#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  int seq[n];

  bool a, b = 0;

  for (size_t i = 0; i < n; i++) {
    cin >> seq[i];

    if(seq[i] == 1){
      a = !a;
    }else{
      a = !a;
      b = !b;
    }
  }

  cout << a << endl << b << endl;

  return 0;
}
