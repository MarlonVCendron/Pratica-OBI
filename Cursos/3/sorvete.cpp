#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;

int main(){
  int p, s;
  cin >> p >> s;
  pii tmp;

  pii intervalos[s];

  for (size_t i = 0; i < s; i++) {
    cin >> tmp.first >> tmp.second;
    intervalos[i] = tmp;
  }

  sort(intervalos, intervalos+s);

  pii intervaloAtual = intervalos[0];
  for (size_t i = 1; i < s; i++) {
    if (intervalos[i].first <= intervaloAtual.second) {
      intervaloAtual.second = max(intervaloAtual.second, intervalos[i].second);
    }else{
      cout << intervaloAtual.first << " " << intervaloAtual.second << endl;

      intervaloAtual = intervalos[i];
    }
  }

  cout << intervaloAtual.first << " " << intervaloAtual.second << endl;

  return 0;
}
