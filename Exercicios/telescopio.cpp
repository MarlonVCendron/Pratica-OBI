#include <iostream>
using namespace std;

int main(){
  int a, n; cin >> a >> n;
  int estrelas[n];

  int total = 0;

  for (size_t i = 0; i < n; i++) {
    cin >> estrelas[i];

    if (estrelas[i] * a >= 40000000) total++;
  }

  cout << total << endl;

  return 0;
}
