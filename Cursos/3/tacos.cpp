#include <iostream>
#include <set>
using namespace std;

int main(){
  int c;
  cin >> c;

  int tmp;
  set<int> tacos;

  int total = 0;

  for (int i = 0; i < c; i++) {
    cin >> tmp;

    if (tacos.find(tmp) == tacos.end()) {
      tacos.insert(tmp);
      total += 2;
    }else{
      tacos.erase(tmp);
    }
  }

  cout << total << endl;

  return 0;
}
