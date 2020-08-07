#include <iostream>
using namespace std;

void constructTree(int *arr, int *tree, int i, int j, int pos){
  if(i == j){
    tree[pos] = arr[i];
  }else{
    constructTree(arr, tree,         i, (i+j)/2, 2*pos);
    constructTree(arr, tree, (i+j)/2+1,       j, 2*pos+1);
    tree[pos] = tree[2*pos] * tree[2*pos+1];
  }
}

int treeQuery(int *tree, int qi, int qj, int i, int j, int pos){
  if (qi <= i && qj >= j) { // Total overlap
    return tree[pos];
  }else if(qi > j || qj < i){ // No overlap
    return 1;
  }

  int mid = (i+j) / 2;

  return treeQuery(tree, qi, qj, i, (i+j)/2, 2*pos) * treeQuery(tree, qi, qj, (i+j)/2 + 1, j, 2*pos+1);
}

void updateTree(int *arr, int *tree, int i, int j, int pos, int changePos, int newValue){
  if (i == j){
    arr[changePos] = newValue;
    tree[pos] = newValue;
  }else{
    int mid = (i+j) / 2;

    if (changePos <= mid)
      updateTree(arr, tree,     i, mid,     2*pos, changePos, newValue);
    else
      updateTree(arr, tree, mid+1,   j, 2*pos + 1, changePos, newValue);

    tree[pos] = tree[2*pos] * tree[2*pos + 1];
  }
}


int main(){
  int n, k;
  while(cin >> n >> k){
    int nums[n+1], tree[2*n];
    int tmp;

    for (size_t i = 1; i <= n; i++) {
      cin >> tmp;
      if (tmp > 0) tmp = 1;
      else if (tmp < 0) tmp = -1;

      nums[i] = tmp;
    }

    constructTree(nums, tree, 1, n, 1);

    char op;
    int x, y;
    for (size_t i = 0; i < k; i++) {
      cin >> op >> x >> y;

      if (op == 'C') {
        updateTree(nums, tree, 1, n, 1, x, y);
      }else{
        int value = treeQuery(tree, x, y, 1, n, 1);

        if (value > 0) cout << "+";
        else if (value < 0) cout << "-";
        else cout << "0";
      }
    }

    cout << endl;
  }
  return 0;
}
