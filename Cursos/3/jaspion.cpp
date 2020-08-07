#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(){
  int t; cin >> t;
  int m, n;
  string output = "";

  map<string, string> dicio;

  for (size_t a = 0; a < t; a++) {
    cin >> m >> n;

    cin.ignore();
    string jp, pt;
    for (size_t i = 0; i < m; i++) {
      getline(cin, jp);
      getline(cin, pt);

      dicio[jp] = pt;
    }

    // for (map<string, string>::iterator it = dicio.begin(); it != dicio.end(); ++it) {
    //   cout << (*it).first << " " << (*it).second << endl;
    // }

    // cin.ignore();

    string line;
    for (size_t i = 0; i < n; i++) {
      getline(cin, line);

      string word = "";
      for(auto c : line){
        if(c == ' '){
          if(dicio.find(word) != dicio.end()){
            output = output + dicio[word] + " ";
          }else{
            output = output + word + " ";
          }

          word = "";
        }else{
          word = word + c;
        }
      }

      if(dicio.find(word) != dicio.end()){
        output = output + dicio[word] + " ";
      }else{
        output = output + word + " ";
      }

      output = output + "\n";
    }
    output = output + "\n";
  }

  output.pop_back();
  output.pop_back();
  cout << output << endl;

  return 0;
}
