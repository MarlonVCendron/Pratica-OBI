#include <iostream>

#define pii pair<int,int>

using namespace std;

void constructTree(int *arr, pii *tree, int i, int j, int pos){
  if(i == j){
    tree[pos] = pii(arr[i], 1);
  }else{
    constructTree(arr, tree, i, (i+j)/2, 2*pos);
    constructTree(arr, tree, (i+j)/2 + 1, j, 2*pos+1);

    pii esquerda = tree[2*pos];
    pii direita = tree[2*pos+1];
    pii total = pii(esquerda.first + direita.first, esquerda.second + direita.second);

    if (esquerda > direita && esquerda > total) tree[pos] = esquerda;
    else if (direita > esquerda && direita > total) tree[pos] = direita;
    else tree[pos] = total;
  }
}

pii queryTree(pii *tree, int i, int j, int pos, int qi, int qj){
  return pii(0,0);
}

int main(){
  int t, n, q, a, b; cin >> t;

  for (size_t z = 0; z < t; z++) {
    cin >> n;
    int saldos[n+1];
    pii tree[2*n];

    for (size_t i = 1; i <= n; i++) {
      cin >> saldos[i];
    }

    constructTree(saldos, tree, 1, n, 1);

    for (size_t i = 1; i < 2*n; i++) {
      cout << i << ":  " << tree[i].first << " " << tree[i].second << endl;
    }

    // cin >> q;
    //
    // for (size_t i = 0; i < q; i++) {
    //   cin >> a >> b;
    //   pii res = queryTree(tree, 1, n, 1, a, b);
    //   cout << res.first << ' ' << res.second << endl;
    // }

  }

  return 0;
}
