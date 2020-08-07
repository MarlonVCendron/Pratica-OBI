#include <iostream>
using namespace std;

int main(){
  int n, a, b; cin >> n >> a >> b;
  int arr[n];
  for (size_t i = 0; i < n; i++) {
    cin >> arr[i];
  }

  int total = 0;
  for (size_t i = 0; i < n; i++) {
    for (size_t j = i+1; j < n; j++) {
      int p = arr[i] + arr[j];
      if(p >= a && p <= b) total++;
    }
  }

  cout << total << endl;
  return 0;
}
