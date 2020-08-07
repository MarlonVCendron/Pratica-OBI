#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  int n, m;
  cin >> n >> m;
  int medalhas[m][3];
  int paises[n];
  float pontos[n];

  for (size_t i = 0; i < n; i++) {
    pontos[i] = 0;
    paises[i] = i+1;
  }

  for (size_t i = 0; i < m; i++) {
    for (size_t j = 0; j < 3; j++) {
      cin >> medalhas[i][j];
      if(j == 0){
        pontos[medalhas[i][j]-1] += 100000;
      }else if(j == 1){
        pontos[medalhas[i][j]-1] += 100;
      }else{
        pontos[medalhas[i][j]-1] += 1;
      }
    }
  }

  bool ordenado = false;
  while(!ordenado){
    ordenado = true;
    for (size_t i = 0; i < n-1; i++) {
      if(pontos[i] < pontos[i+1]){
        ordenado = false;
        float tmp = pontos[i];
        pontos[i] = pontos[i+1];
        pontos[i+1] = tmp;

        float tmp2 = paises[i];
        paises[i] = paises[i+1];
        paises[i+1] = tmp2;
      }
    }
  }

  for (size_t i = 0; i < n; i++) {
    cout << paises[i] << " ";
  }

  cout << endl;

  return 0;
}
