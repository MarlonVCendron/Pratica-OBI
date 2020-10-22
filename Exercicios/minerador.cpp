#include <iostream>
using namespace std;

int main(){
  int n, m;
  cin >> n >> m;

  float values[n], earnings[n], net[n];

  for (int i = 0; i < n; i++) cin >> values[i];

  for (int i = 0; i < n; i++) {
    float x;
    cin >> x;
    earnings[i] = x;
    if(i != 0) earnings[i] += earnings[i-1];

    net[i] = values[i] * earnings[i] * m;
  }

  float maxV = -1, minV = 99999999;
  int maxI, minI;
  for (size_t i = 0; i < n; i++) {
    if(net[i] > maxV){
      maxV = net[i];
      maxI = i;
    }

    if(net[i] < minV){
      minV = net[i];
      minI = i;
    }
  }

  printf("%d %.2f\n", maxI+1, maxV);
  printf("%d %.2f\n", minI+1, minV);

  return 0;
}
