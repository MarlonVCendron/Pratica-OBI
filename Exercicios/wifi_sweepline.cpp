#include <bits/stdc++.h>
#include <iostream>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

typedef tuple<int, int, int, bool> ev;
#define OPEN 0
#define CLOSE 1
#define F first
#define S second

int main(){_;
  int n; cin >> n;
  vector<ev> r;

  for (int a, b, c, d, i = 0; i < n; i++) {
    cin >> a >> b >> c >> d;

    r.push_back(ev(a, d, b, OPEN));
    r.push_back(ev(c, d, b, CLOSE));
  }

  sort(r.begin(), r.end());

  int total = 0;
  map<int, int> yOcupados;
  for (const auto &e : r) {
    // cout << "---------------------" << endl;
    // for (map<int, int>::iterator iter = yOcupados.begin(); iter != yOcupados.end(); iter++) {
    //   cout << iter->first << "(" << iter->second << ") ";
    // }
    // cout << endl << "---------------------" << endl;
    //
    // cout << get<0>(e) << " " << get<1>(e) << " " << get<2>(e) << " " << get<3>(e) << endl;
    
    if(get<3>(e) == 0){
      yOcupados[get<1>(e)] = 0;
      yOcupados[get<2>(e)] = 1;
    }else{
      if(yOcupados[get<1>(e)] == 0) total++;
      map<int, int>::iterator it = yOcupados.find(get<1>(e));
      --it;
      it->second = 1;
      yOcupados.erase(get<1>(e));
      yOcupados.erase(get<2>(e));
    }
  }

  cout << total << endl;

  return 0;
}
