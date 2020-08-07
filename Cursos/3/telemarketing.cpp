#include <iostream>
#include <queue>
using namespace std;

int main(){
  int n, l; cin >> n >> l;
  int vendedores[n], tmp, totalVendedores[n];
  queue<int> tempos;

  for (size_t i = 0; i < n; i++) {
    vendedores[i] = 0;
    totalVendedores[i] = 0;
  }

  for (size_t i = 0; i < l; i++) {
    cin >> tmp;
    tempos.push(tmp);
  }

  int count = 0;
  while (!tempos.empty()) {
    for (size_t i = 0; i < n; i++) {
      if (vendedores[i] <= count) {
        vendedores[i] += tempos.front();
        tempos.pop();
        totalVendedores[i]++;

        if(tempos.empty()) break;
      }
    }

    count++;
  }

  for (size_t i = 0; i < n; i++) {
    cout << (i+1) << " " << totalVendedores[i] << endl;
  }

  return 0;
}
