#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  int m[n][n];
  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < n; j++) {
      cin >> m[i][j];
    }
  }

  int maior = 0;
  int linhas[n], colunas[n];

  for (size_t i = 0; i < n; i++) {
    int somaLinha = 0, somaColuna = 0;
    for (size_t j = 0; j < n; j++) {
      somaLinha += m[i][j];
      somaColuna += m[j][i];
    }
    linhas[i] = somaLinha;
    colunas[i] = somaColuna;
  }


  int soma = 0;
  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < n; j++) {
      soma = linhas[i] + colunas[j] - 2*m[i][j];
      if(soma > maior){
        maior = soma;
      }
    }
  }

  cout << maior << endl;

  return 0;
}
