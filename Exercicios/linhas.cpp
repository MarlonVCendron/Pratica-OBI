#include <iostream>
using namespace std;

int main(){
  int n;
  cin >> n;
  int linhas[n];
  int ocorrencias[n];

  for (size_t i = 0; i < n; i++) {
    cin >> linhas[i];
    ocorrencias[i] = 0;
  }

  int total = 0;
  for (size_t i = 0; i < n; i++) {
    for (size_t j = i; j < n; j++) {
      if (linhas[j] < linhas[i]) total++;
    }
  }

  cout << total << endl;
  return 0;
}
