#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define OPEN 1
#define CLOSE 0
#define F first
#define S second

int main(){
  vector<pair<int, bool>> ev;

  ev.push_back({0, CLOSE});
  for (int x, i = 0; i < 3; i++) {
    cin >> x;

    ev.push_back({x, OPEN});
    ev.push_back({x+200, CLOSE});
  }
  ev.push_back({600, OPEN});

  sort(ev.begin(), ev.end());

  int total = 0, open = 0;
  for (size_t i = 1; i < ev.size(); i++) {
    if (open == 0) {
      total += ev[i].F - ev[i-1].F;
    }

    if(ev[i].S == OPEN) open++;
    else open--;
  }

  cout << total * 100 << endl;

  return 0;
}
