#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  char g[n], r[n];
  cin >> g;
  cin >> r;

  int total = 0;

  for (size_t i = 0; i < n; i++) {
    if(g[i] == r[i]){
      total++;
    }
  }

  cout << total << endl;
  return 0;
}
