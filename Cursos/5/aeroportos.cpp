#include <iostream>
#include <vector>
using namespace std;

#define MAXS 1010

int a, v;
int flights[MAXS];

int main(){
  int count = 0;
  while (true) {
    cin >> a >> v;
    if(a == 0) break;

    count++;

    for (size_t i = 1; i <= a; i++) flights[i] = 0;

    int x, y;
    for (size_t i = 0; i < v; i++) {
      cin >> x >> y;
      flights[x]++;
      flights[y]++;
    }

    vector<int> maiores;

    int max = -1;
    for (size_t i = 1; i <= a; i++) {
      if(flights[i] >= max){
        if(flights[i] > max){
          maiores.erase(maiores.begin(), maiores.end());
          max = flights[i];
        }
        maiores.push_back(i);
      }
    }

    cout << "Teste " << count << endl;
    for (const auto &m : maiores) {
      cout << m << ' ';
    }
    cout << endl << endl;
  }

  return 0;
}
