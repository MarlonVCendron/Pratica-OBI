#include <iostream>
#include <cstring>
using namespace std;

int main(){

  // PÉSSIMO, talvez tenha complexidade O(n⁵) e nem dá a resposta certa


  // int n, p; cin >> n >> p;
  // int tabuleiro[n][n] = {};
  // int pretas = p, brancas = p;
  //
  // int l, c;
  // for (size_t i = 0; i < p; i++) {
  //   cin >> l >> c;
  //   tabuleiro[l-1][c-1] = 1;
  // }
  // for (size_t i = 0; i < p; i++) {
  //   cin >> l >> c;
  //   tabuleiro[l-1][c-1] = 2;
  // }
  //
  // // Para todas as dimensões de sub-matrizes
  // for (size_t i = 2; i <= n; i++) {
  //   // cout << i << endl;
  //
  //   // Para cada início horizontal da sub-matriz
  //   for (size_t x = 0; x <= n-i; x++) {
  //     // Para cada início vertical da sub-matriz
  //     for (size_t y = 0; y <= n-i; y++) {
  //       // cout << "  " << x << " " << y << endl;
  //
  //       bool localPretas = false, localBrancas = false;
  //
  //       // Para cada coluna da sub-matriz
  //       for (size_t j = x; j < x+i; j++) {
  //         // Para cada linha da sub-matriz
  //         for (size_t k = y; k < y+i; k++) {
  //           // cout << "    " << j << " " << k << endl;
  //
  //           if(tabuleiro[j][k] == 1) localPretas = true;
  //           else if(tabuleiro[j][k] == 2) localBrancas = true;
  //
  //           if(localPretas && localBrancas) break;
  //         }
  //         if(localPretas && localBrancas){
  //           continue;
  //         }else{
  //           if(localPretas) pretas++;
  //           else if(localBrancas) brancas++;
  //         }
  //
  //         localPretas = false, localBrancas = false;
  //       }
  //
  //     }
  //   }
  // }
  //
  // cout << pretas << " " << brancas << endl;
  //
  // // Print tabuleiro
  // // for (size_t i = 0; i < n; i++) {
  // //   for (size_t j = 0; j < n; j++) {
  // //     cout << tabuleiro[i][j] << " ";
  // //   }
  // //   cout << endl;
  // // }
  // return 0;
}
