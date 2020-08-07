#include <iostream>
#include <string>
#include <stack>
#include <stdio.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  stack<char> chaves;
  string tmp;

  for (size_t i = 0; i <= n; i++) {
    getline(cin, tmp);

    for (size_t j = 0; j < tmp.size(); j++) {
      if(tmp[j] == '{'){
        chaves.push(tmp[j]);
      }else if(tmp[j] == '}'){
        if (chaves.empty()) {
          cout << 'N' << endl;
          exit(0);
        }

        chaves.pop();
      }
    }
  }

  if (!chaves.empty()) {
    cout << 'N' << endl;
  }else{
    cout << 'S' << endl;
  }


  return 0;
}
