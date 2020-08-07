#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  int fita[n], colorida[n];
  for (size_t i = 0; i < n; i++) {
    cin >> fita[i];
    if(fita[i] == 0){
      colorida[i] = 0;
    }else{
      colorida[i] = 9;
    }
  }

  for (size_t i = 0; i < n; i++) {
    if (fita[i] == 0) {
      for (size_t j = i-1; j < -1; j--) {
        int d = i-j;
        if (d < colorida[j]) {
          colorida[j] = d;
        }
      }
      for (size_t j = i+1; j < n; j++) {
        int d = j-i;
        if (d < colorida[j]) {
          colorida[j] = d;
        }
      }
    }
  }

  for (size_t i = 0; i < n; i++) {
    cout << colorida[i] << " ";
  }

  cout << endl;

  return 0;
}
