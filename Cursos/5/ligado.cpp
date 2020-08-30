#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAXS 100010

int n, m, t, a, b;

int main(){
  cin >> n >> m;

  int respostas[m];
  vector<int> pontes[n+1];

  for (size_t i = 0; i < m; i++) {
    respostas[i] = 0;
  }

  int totalP = 0;

  for (size_t i = 0; i < m; i++) {
    cin >> t;
    cin >> a;
    cin >> b;

    if(t == 0){
      auto it = find(pontes[a].begin(), pontes[a].end(), b);
      if(it != pontes[a].end()) respostas[totalP] = 1;
      totalP++;
    }else{
      pontes[a].push_back(b);
      pontes[b].push_back(a);
    }
  }

  for (size_t i = 0; i < totalP; i++) {
    cout << respostas[i] << endl;
  }

  return 0;
}
