#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  int n;
  cin >> n;

  int nums[n];
  for (size_t i = 0; i < n; i++) {
    cin >> nums[i];
  }

  int last = nums[0];
  int currentStreak = 1;
  int biggest = 0;
  for (size_t i = 1; i < n; i++) {
    if (nums[i] == last) {
      currentStreak++;
    }else{
      if (currentStreak > biggest) {
        biggest = currentStreak;
      }
      last = nums[i];
      currentStreak = 1;
    }
  }

  if (currentStreak > biggest) {
    biggest = currentStreak;
  }

  cout << biggest << endl;

  return 0;
}
