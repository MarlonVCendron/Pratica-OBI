#include <iostream>
#include <algorithm>
using namespace std;

int findBin(int *arr, int n, int k){
  int ini = 0, fim = n, meio;
  while (ini <= fim) {
    meio = (fim+ini)/2;
    if(arr[meio] == k) return meio;
    if(arr[meio] > k) fim = meio - 1;
    if(arr[meio] < k) ini = meio + 1;
  }
  return -1;
}

int main(){
  int n, k;
  cin >> n;
  int nums[n];
  for (size_t i = 0; i < n; i++) {
    cin >> nums[i];
  }
  cin >> k;

  for (size_t i = 0; i < n; i++) {
    auto idx = findBin(nums, n, k-nums[i]);
    if(idx != -1){
      cout << nums[i] << " " << k-nums[i] << endl;
      return 0;
    }
  }

  return 0;
}
