#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  char s[60], vogais[60];
  cin >> s;

  int totalVogais = 0;

  for (size_t i = 0; i < 60; i++) {
    if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
      vogais[totalVogais] = s[i];
      totalVogais++;
    }
  }

  for (size_t i = 0; i < totalVogais; i++) {
    if(vogais[i] != vogais[totalVogais-1-i]){
      cout << "N" << endl;
      return 0;
    }
  }

  cout << "S" << endl;

  return 0;
}
