#include <iostream>
#include <vector>
using namespace std;

int calcularPeso(int p, vector<int>* grafo){
  int peso = grafo[p].size();
  for(const auto& v: grafo[p]){
    peso += calcularPeso(v, grafo);
  }
  return peso;
}

int main(){
  int n, p, q; cin >> n;
  vector<int> grafo[n+1];

  for (size_t i = 0; i < n; i++) {
    cin >> p >> q;
    grafo[q].push_back(p);
  }

  for (size_t i = 0; i < n; i++) {
    if(grafo[i].size() <= 1) continue;

    int peso = -1;
    for(const auto& p: grafo[i]){
      int currentPeso = calcularPeso(p, grafo);

      if (peso == -1){
        peso = currentPeso;
      }else{
        if (peso != currentPeso) {
          cout << "mal" << endl;
          return 0;
        }
      }
    }
  }

  cout << "bem" << endl;

  // for (size_t i = 0; i < n+1; i++) {
  //   cout << i << ":  ";
  //   for(const auto& p: grafo[i]){
  //     cout << p << " ";
  //   }
  //   cout << endl;
  // }


  return 0;
}
