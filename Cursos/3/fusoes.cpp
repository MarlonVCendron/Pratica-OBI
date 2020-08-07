#include <iostream>
using namespace std;

#define MAX 100010

int pai[MAX];
int n, k;

int find(int x){
  if (pai[x] == x) return x;
  return pai[x] = find(pai[x]);
}

void join(int x, int y){
  int a = find(x);
  int b = find(y);

  if(a==b) return;

  pai[a] = b;
}

int main(){
  cin >> n >> k;

  char c;
  int x, y;

  for (size_t i = 1; i <= n; i++) {
    pai[i] = i;
  }

  for (size_t i = 0; i < k; i++) {
    cin >> c >> x >> y;

    if (c == 'F') {
      join(x, y);
    }else{
      if(find(x) == find(y)){
        cout << 'S' << endl;
      }else{
        cout << 'N' << endl;
      }
    }
  }

  return 0;
}
