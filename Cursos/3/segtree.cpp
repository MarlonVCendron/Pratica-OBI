#include <iostream>
using namespace std;

#define MAX 4

void constructTree(int *arr, int *tree, int i, int j, int pos){
  if (i == j) {
    tree[pos] = arr[i];
  }else{
    constructTree(arr, tree,           i, (i+j)/2, 2*pos+1);
    constructTree(arr, tree, (i+j)/2 + 1,       j, 2*pos+2);
    tree[pos] = min(tree[2*pos+1], tree[2*pos+2]);
  }
}

int main(){
  int arr[MAX] = {0, -5, 2, 8};
  int tree[MAX*2 - 1];

  constructTree(arr, tree, 0, 3, 0);

  for (size_t i = 0; i < MAX*2-1; i++) {
    cout << tree[i] << endl;
  }

  return 0;
}
