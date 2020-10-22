#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(){
  int n, k; cin >> n;
  int arr[n];
  set<int> s;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    s.insert(arr[i]);
  }

  cin >> k;

  for (size_t i = 0; i < n; i++) {
    if(s.find(k - arr[i]) != s.end()){
      cout << arr[i] << " " << k - arr[i] << endl;
      return 0;
    }
  }
  return 0;
}
