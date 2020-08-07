#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <vector>

using namespace std;

#define NOTAS 9

int n, q, a, b, size;

int maxIndex(vector<int> const &arr){
  int index = 0;
  for (size_t i = 0; i < NOTAS; i++) {
    if(arr[i] >= arr[index]){
      index = i;
    }
  }

  return index;
}

void printTree(vector<vector<int>> const &tree){
  for (size_t i = 0; i < size; i++) {
    cout << i << ":   ";
    for (size_t j = 0; j < NOTAS; j++) {
      cout << tree[i][j] << " ";
    }
    cout << endl;
  }
}

void constructTree(int *arr, vector<vector<int>> &tree, int i, int j, int pos){
  if(i == j){
    for (size_t k = 0; k < NOTAS; k++) {
      tree[pos][k] = 0;
    }
    tree[pos][1] = 1;
    arr[i] = 1;
  }else{
    int mid = (i+j)/2;
    constructTree(arr, tree, i, mid, 2*pos+1);
    constructTree(arr, tree, mid+1, j, 2*pos+2);
    for (size_t k = 0; k < NOTAS; k++) {
      tree[pos][k] = tree[2*pos+1][k] + tree[2*pos+2][k];
    }
  }
}

auto query(vector<vector<int>> const &tree, int i, int j, int pos, int qi, int qj){
  if(qi <= i && qj >= j){
    return tree[pos];
  }else if(qi > j || qj < i){
    vector<int> empty;
    for (size_t k = 0; k < NOTAS; k++) {
      empty.push_back(0);
    }
    return empty;
  }

  int const mid = (i+j)/2;

  auto const left  = query(tree,     i, mid, 2*pos+1, qi, qj);
  auto const right = query(tree, mid+1,   j, 2*pos+2, qi, qj);

  vector<int> total;

  total.reserve(NOTAS);
  for (size_t k = 0; k < NOTAS; k++) {
    total.push_back(0);
  }

  for (size_t k = 0; k < NOTAS; k++) {
    total[k] = left[k] + right[k];
  }

  return total;
}

void updateTree(int *arr, vector<vector<int>> &tree, int i, int j, int pos, int changePos, int value){
  if(i == j){
    int newNote = (arr[i] + value) % NOTAS;
    for (size_t k = 0; k < NOTAS; k++) {
      tree[pos][k] = 0;
    }
    tree[pos][newNote] = 1;
    arr[i] = newNote;
  }else{
    int mid = (i+j)/2;

    if(changePos <= mid)
      updateTree(arr, tree, i, mid, 2*pos+1, changePos, value);
    else
      updateTree(arr, tree, mid+1, j, 2*pos+2, changePos, value);

    for (size_t k = 0; k < NOTAS; k++) {
      tree[pos][k] = tree[2*pos+1][k] + tree[2*pos+2][k];
    }
  }
}


int main(){
  cin >> n >> q;
  int arr[n];
  size = 2 * pow(2, ceil(log2(n))) - 1;
  vector<vector<int>> tree;

  for (size_t i = 0; i < size; i++) {
    tree.push_back(vector<int>{});
    for (size_t j = 0; j < NOTAS; j++) {
      tree[i].push_back(0);
    }
  }

  constructTree(arr, tree, 0, n-1, 0);

  for (size_t z = 0; z < q; z++) {
    cin >> a >> b;

    auto const freq = query(tree, 0, n-1, 0, a, b);
    int note = maxIndex(freq);

    for (size_t i = a; i <= b; i++) {
      updateTree(arr, tree, 0, n-1, 0, i, note);
    }
  }

  for (size_t i = 0; i < n; i++) {
    cout << arr[i] << endl;
  }


  return 0;
}
