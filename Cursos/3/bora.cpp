#include <iostream>
#include <queue>
#include <vector>
#include <math.h>
#include <bits/stdc++.h>
#include <string>
using namespace std;

int main(){
  int p, m, n;
  int x;
  char s;
  vector<int> output;

  while (true) {
    cin >> p >> m >> n;

    if (p == 0) {
      break;
    }

    queue<float> monte;
    vector<float> jogadores[p];

    for (size_t i = 0; i < n; i++) {
      cin >> x >> s;

      float cartaAtual = x;
      switch (s) {
        case 'C':
          cartaAtual += 0.2;
          break;
        case 'D':
          cartaAtual += 0.4;
          break;
        case 'H':
          cartaAtual += 0.6;
          break;
        case 'S':
          cartaAtual += 0.8;
          break;
      }
      monte.push(cartaAtual);
    }

    for (size_t i = 0; i < p; i++) {
      for (size_t j = 0; j < m; j++) {
        jogadores[i].insert(jogadores[i].begin(), monte.front());
        monte.pop();
      }
    }

    float descarte = monte.front();
    monte.pop();

    int dir = 1;
    int jogadorAtual = 0;
    bool jogou = 1;

    while (true) {
      if(jogou){
        if (floor(descarte) == 12) {
          dir *= -1;
        }else if(floor(descarte) == 7){
          jogadores[jogadorAtual].insert(jogadores[jogadorAtual].begin(), monte.front());
          monte.pop();
          jogadores[jogadorAtual].insert(jogadores[jogadorAtual].begin(), monte.front());
          monte.pop();

          jogadorAtual = (p + ((jogadorAtual + dir)%p)) % p;
        }else if(floor(descarte) == 1){
          jogadores[jogadorAtual].insert(jogadores[jogadorAtual].begin(), monte.front());
          monte.pop();

          jogadorAtual = (p + ((jogadorAtual + dir)%p)) % p;
        }else if(floor(descarte) == 11){
          jogadorAtual = (p + ((jogadorAtual + dir)%p)) % p;
        }

      }

      sort(jogadores[jogadorAtual].begin(), jogadores[jogadorAtual].end(), greater<int>());

      jogou = 0;
      
      for (size_t i = 0; i < jogadores[jogadorAtual].size(); i++) {
        auto strDescarte = to_string(fmod(descarte, 1.0));
        auto strCarta = to_string(fmod(jogadores[jogadorAtual][i], 1.0));

        if (floor(jogadores[jogadorAtual][i]) == floor(descarte) || strDescarte.compare(strCarta) == 0) {
          descarte = jogadores[jogadorAtual][i];
          jogadores[jogadorAtual].erase(jogadores[jogadorAtual].begin() + i);
          jogou = 1;
          break;
        }
      }

      if(!jogou){
        auto strDescarte = to_string(fmod(descarte, 1.0));
        auto strCarta = to_string(fmod(monte.front(), 1.0));

        if (floor(monte.front()) == floor(descarte) || strDescarte.compare(strCarta) == 0) {
          descarte = monte.front();
          jogou = 1;
        }else{
          jogadores[jogadorAtual].insert(jogadores[jogadorAtual].begin(), monte.front());
        }

        monte.pop();
      }

      if(jogadores[jogadorAtual].size() == 0){
        output.insert(output.end(), jogadorAtual+1);
        break;
      }

      jogadorAtual = (p + ((jogadorAtual + dir)%p)) % p;
    }
  }

  for (size_t i = 0; i < output.size(); i++) {
    cout << output[i] << endl;
  }

  return 0;
}
