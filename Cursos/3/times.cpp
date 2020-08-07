#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, string> aluno;

int main(){
  int n, t;
  cin >> n >> t;
  vector<aluno> alunos;
  vector<aluno> times[n];

  int h;
  string nome;
  for (size_t i = 0; i < n; i++) {
    cin >> nome >> h;
    alunos.insert(alunos.begin(), aluno(h, nome));
  }

  sort(alunos.begin(), alunos.end(), greater<aluno>());

  for (size_t i = 0; i < n; i++) {
    times[i%t].insert(times[i%t].end(), alunos[i]);
  }

  for (size_t i = 0; i < t; i++) {
    cout << "Time " << i+1 << endl;
    sort(times[i].begin(), times[i].end(), [](auto &left, auto &right) {
      return left.second < right.second;
    });
    for (size_t j = 0; j < times[i].size(); j++) {
      cout << times[i][j].second << endl;
    }
    cout << endl;
  }

  return 0;
}
