#include <iostream>
#include <algorithm>
using namespace std;

struct horario{
  int inicio;
  int final;
};

bool compara(struct horario a, struct horario b){
  return a.inicio < b.inicio;
}

int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  struct horario h[n];
  for (size_t i = 0; i < n; i++) {
    struct horario tmp;
    cin >> tmp.inicio;
    cin >> tmp.final;
    h[i] = tmp;
  }

  sort(h, h+n, compara);

  int total = 1;
  int ultimoH = h[0].final;
  for (size_t i = 1; i < n; i++) {
    if(h[i].inicio >= ultimoH){
      total++;
      ultimoH = h[i].final;
    }
  }

  // for (size_t i = 0; i < n; i++) {
  //   cout << h[i].inicio << " " << h[i].final << endl;
  // }

  cout << total << endl;

  return 0;
}
