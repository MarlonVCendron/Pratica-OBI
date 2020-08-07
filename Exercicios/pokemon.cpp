#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
  int n; cin >> n;
  vector<int> levels;

  int tmp;
  for (size_t i = 0; i < 3; i++) {
    cin >> tmp;
    levels.push_back(tmp);
  }

  sort(levels.begin(), levels.end());

int total = 0;
  for (size_t i = 0; i < 3; i++) {
    n -= levels[i];

    if(n < 0) break;
    total++;
  }

  cout << total << endl;
  return 0;
}
