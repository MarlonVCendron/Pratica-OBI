#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
#define MAX 1010
int main(){
  string stringC, txt;
  getline(cin, stringC);
  getline(cin, txt);
  char c = stringC[0];

  float totalPalavras = 0.0, totalComC = 0.0;
  bool temC = false;

  for(char& ch : txt){
    if(ch == ' '){
      totalPalavras++;
      if(temC) totalComC++;
      temC = false;
    }

    if(ch == c) temC = true;
  }

  totalPalavras++;
  if(temC) totalComC++;
  temC = false;

  printf("%.1f\n", totalComC / totalPalavras * 100.0 );
  return 0;
}
