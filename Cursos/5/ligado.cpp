#include <iostream>
using namespace std;

int main(){
  int n, m, t, a, b;
  cin >> n >> m;

  int respostas[m], pontes[n+1][n+1] = {};
  int totalP = 0;

  for (size_t i = 0; i < m; i++) {
    cin >> t;
    cin >> a;
    cin >> b;

    if(t == 0){
      respostas[totalP] = pontes[a][b];
      totalP++;
    }else{
      pontes[a][b] = 1;
      pontes[b][a] = 1;
    }
  }

  for (size_t i = 0; i < totalP; i++) {
    cout << respostas[i] << endl;
  }

  return 0;
}
