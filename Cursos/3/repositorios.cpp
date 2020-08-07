#include <iostream>
#include <map>
using namespace std;

int main(){
  int c, n; cin >> c >> n;
  int p, v;

  map<int, int> programas;
  map<int, int> instalados;

  for (size_t i = 0; i < c; i++) {
    cin >> p >> v;
    programas[p] = v;
  }

  for (size_t i = 0; i < n; i++) {
    cin >> p >> v;

    if (programas.find(p) != programas.end()) {
      if (programas[p] < v) {
        programas[p] = v;
        instalados[p] = v;
      }
    }else{
      programas[p] = v;
      instalados[p] = v;
    }
  }

  for (map<int, int>::iterator it = instalados.begin(); it != instalados.end(); ++it) {
    cout << (*it).first << " " << (*it).second << endl;
  }

  return 0;
}
