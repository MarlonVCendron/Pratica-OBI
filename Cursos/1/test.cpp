#include <iostream>
using namespace std;

int main() {

  for (size_t i = 0; i < 4; i++) {
    for (size_t j = 4-1; j > 0; j--) {
      cout << i << " " << j << endl;
    }
  }

  return 0;
}
