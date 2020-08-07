#include <iostream>
#include <queue>
using namespace std;

int main(){
  int m, n;
  queue<char> times;

  times.push('A');
  times.push('B');
  times.push('C');
  times.push('D');
  times.push('E');
  times.push('F');
  times.push('G');
  times.push('H');
  times.push('I');
  times.push('J');
  times.push('K');
  times.push('L');
  times.push('M');
  times.push('N');
  times.push('O');
  times.push('P');

  for (size_t i = 0; i < 15; i++) {
    cin >> m >> n;

    if (m > n) {
      times.push(times.front());
      times.pop();
      times.pop();
    }else{
      times.pop();
      times.push(times.front());
      times.pop();
    }
  }

  cout << times.front() << endl;

  return 0;
}
