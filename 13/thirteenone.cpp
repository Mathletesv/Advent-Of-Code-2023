#include <bits/stdc++.h>
using namespace std;

bool vert_equal(vector<string> lines, int a, int b) {
  for (int i = 0; i < lines.size(); i++) {
    if (lines[i][a] != lines[i][b]) return false;
  }
  return true;
}

int solve(vector<string> lines) {
  for (int i = 0; i < lines.size() - 1; i++) {
    if (lines[i] == lines[i + 1]) {
      for (int j = i, k = i + 1; j >= 0 && k < lines.size(); j--, k++) {
        if (lines[j] != lines[k]) goto END; 
      }
      return 100 * (i + 1);
      END:;
    }
  }
  for (int i = 0; i < lines[0].size() - 1; i++) {
    if (vert_equal(lines, i, i + 1)) {
      for (int j = i, k = i + 1; j >= 0 && k < lines[0].size(); j--, k++) {
        if (!vert_equal(lines, j, k)) goto END2;
      }
      return i + 1;
      END2:;
    }
  }
  return 0;
}

int main() {
  ifstream fin("thirteen.in");

  string line;
  vector<string> lines;
  int sum = 0;
  while (!fin.eof()) {
    getline(fin, line);
    if (line.size() == 0) {
      sum += solve(lines);
      lines.clear();
    }
    else lines.push_back(line);
  }
  sum += solve(lines);
  cout << sum << "\n";
}