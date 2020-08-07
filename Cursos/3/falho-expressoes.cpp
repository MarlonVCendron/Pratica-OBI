#include <iostream>
#include <string>
using namespace std;

int main(){
  int t;
  cin >> t;

  char out[t];
  string exp;

  for (size_t i = 0; i < t; i++) {
    cin >> exp;

    int countP = 0;
    int countB = 0;
    int countC = 0;
    for (size_t j = 0; j < exp.size(); j++) {
      if(exp[j] == '('){
        countP++;
      }else if(exp[j] == ')'){
        countP--;
      }else if(exp[j] == '['){
        countB++;
      }else if(exp[j] == ']'){
        countB--;
      }else if(exp[j] == '{'){
        countC++;
      }else if(exp[j] == '}'){
        countC--;
      }

      if ((countP < 0 || (countP > 0 && (countB != 0 || countC != 0))) ||
          (countB < 0 || (countB > 0 && (countP != 0 || countC != 0))) ||
          (countC < 0 || (countC > 0 && (countB != 0 || countP != 0))))
      {
        out[i] = 'N';
      }
    }

    if (out[i] != 'N') {
      if (countP == 0 && countB == 0 && countC == 0) {
        out[i] = 'S';
      }else{
        out[i] = 'N';
      }
    }
  }

  for (size_t i = 0; i < t; i++) {
    cout << out[i] << endl;
  }

  return 0;
}
