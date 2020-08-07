#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
  int t;
  cin >> t;

  char out[t];
  string tmp;
  stack<char> exp;

  for (size_t i = 0; i < t; i++) {
    cin >> tmp;

    stack<char>().swap(exp);

    out[i] = 'S';
    for (size_t j = 0; j < tmp.size(); j++) {
      if (tmp[j] == '(' || tmp[j] == '[' || tmp[j] == '{') {
        exp.push(tmp[j]);
      }else if(tmp[j] == ')' || tmp[j] == ']' || tmp[j] == '}'){
        if (exp.empty()) {
          out[i] = 'N';
          break;
        }

        if (tmp[j] == ')' && exp.top() == '(' ||
            tmp[j] == ']' && exp.top() == '[' ||
            tmp[j] == '}' && exp.top() == '{')
        {
          exp.pop();
        }else{
          out[i] = 'N';
          break;
        }
      }
    }

    if(!exp.empty()){
      out[i] = 'N';
    }
  }

  for (size_t i = 0; i < t; i++) {
    cout << out[i] << endl;
  }

  return 0;
}
