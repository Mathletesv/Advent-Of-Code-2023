#include <bits/stdc++.h>
using namespace std;

bool vert_equal(vector<string> lines, int a, int b) {
  for (int i = 0; i < lines.size(); i++) {
    if (lines[i][a] != lines[i][b]) return false;
  }
  return true;
}

int solve(vector<string> lines, int old) {
  for (int i = 0; i < lines.size() - 1; i++) {
    if (lines[i] == lines[i + 1]) {
      for (int j = i, k = i + 1; j >= 0 && k < lines.size(); j--, k++) {
        if (lines[j] != lines[k]) goto END; 
      }
      if (100 * (i + 1) != old) return 100 * (i + 1);
      END:;
    }
  }
  for (int i = 0; i < lines[0].size() - 1; i++) {
    if (vert_equal(lines, i, i + 1)) {
      for (int j = i, k = i + 1; j >= 0 && k < lines[0].size(); j--, k++) {
        if (!vert_equal(lines, j, k)) goto END2;
      }
      if (i + 1 != old) return i + 1;
      END2:;
    }
  }
  return 0;
}

char flip(char c) {
  return c == '.' ? '#' : '.';
}

int smudged(vector<string> lines) {
  int old = solve(lines, -1);
  int real = 0;
  for (int i = 0; i < lines.size(); i++) {
    for (int j = 0; j < lines[0].size(); j++) {
      lines[i][j] = flip(lines[i][j]);
      int maybe = solve(lines, old);
      if (maybe != 0 && maybe != old) {
        return maybe;
      }
      lines[i][j] = flip(lines[i][j]);
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
      sum += smudged(lines);
      lines.clear();
    }
    else lines.push_back(line);
  }
  sum += smudged(lines);
  cout << sum << "\n";
}