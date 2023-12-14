#include <bits/stdc++.h>

using namespace std;

int main() {
  ifstream fin("fourteen.in");
  vector<string> lines;
  string line;
  while (!fin.eof()) {
    getline(fin, line);
    lines.push_back(line);
    for (int i = 0; i < line.size(); i++) {
      if (line[i] == 'O') {
        int level = lines.size() - 1;
        for (; level > 0; level--) {
          if (lines[level - 1][i] != '.') break;
        }
        if (level < 0) level = 0;
        if (level < lines.size() - 1) {
          lines[level][i] = 'O';
          lines[lines.size() - 1][i] = '.';
        }
      }
    }
  }
  int sum = 0;
  for (int i = 0; i < lines.size(); i++) {
    for (int j = 0; j < lines[i].size(); j++) {
      if (lines[i][j] == 'O') sum += lines.size() - i;
    }
  }
  cout << sum << "\n";
}