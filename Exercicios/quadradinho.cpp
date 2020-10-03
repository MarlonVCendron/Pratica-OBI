#include <iostream>
#include <cstring>
using namespace std;

int main(){
  int n; cin >> n;
  int tmp, mod[8];

  memset(mod, 0, sizeof(mod));

  int cumulativa = 0;
  for (size_t i = 0; i < n; i++) {
    cin >> tmp;
    cumulativa += tmp;

    mod[((cumulativa % 8) + 8 ) % 8]++;
  }

  int total = 0;
  for (size_t i = 0; i < 8; i++) {
    if (mod[i] > 1)
      total += (mod[i] * (mod[i] - 1)) / 2;
  }

  total += mod[0];

  cout << total << endl;

  return 0;
}
