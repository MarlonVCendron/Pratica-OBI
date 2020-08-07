#include <iostream>
using namespace std;

int main(){
  int m, n;
  cin >> m >> n;
  char a[m][n];

  for (size_t i = 0; i < m; i++) {
    for (size_t j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }

  int total = 0;

  for (size_t i = 0; i < m; i++) {
    for (size_t j = 0; j < n; j++) {
      if(a[i][j] == '#'){
        if(i != n-1){
          if(a[i+1][j] == '.'){
            total++;
            // cout << i << " " << j << endl;
            continue;
          }
        }else{
          total++;
          continue;
        }
        if (j != m-1) {
          if(a[i][j+1] == '.'){
            total++;
            // cout << i << " " << j << endl;
            continue;
          }
        }else{
          total++;
          continue;
        }
        if(i != 0){
          if(a[i-1][j] == '.'){
            total++;
            // cout << i << " " << j << endl;
            continue;
          }
        }else{
          total++;
          continue;
        }
        if(j != 0){
          if(a[i][j-1] == '.'){
            total++;
            // cout << i << " " << j << endl;
            continue;
          }
        }else{
          total++;
          continue;
        }
      }
    }
  }

  cout << total << endl;

  return 0;
}
