#include <iostream>
#include <string.h>
using namespace std;

int main(int argc, char const *argv[]) {
  int n, count[10];
  cin >> n;
  char nums[n][100];

  for (size_t i = 0; i < 10; i++) {
    count[i] = 0;
  }

  for (size_t i = 0; i < n; i++) {
    cin >> nums[i];
    for (size_t j = 0; j < strlen(nums[i]); j++) {
      count[(nums[i][j]-'0')]++;
    }
  }

  for (size_t i = 0; i < 10; i++) {
    cout << i << " - " << count[i] << endl;
  }

  return 0;
}
