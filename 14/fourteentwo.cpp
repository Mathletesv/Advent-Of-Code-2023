#include <bits/stdc++.h>

using namespace std;

vector<string> north(vector<string> lines) {
  for (int i = 0; i < lines.size(); i++) {
    for (int j = 0; j < lines[i].size(); j++) {
      if (lines[i][j] == 'O') {
        int level = i;
        for (; level > 0; level--) {
          if (lines[level - 1][j] != '.') break;
        }
        lines[i][j] = '.';
        lines[level][j] = 'O';
      }
    }
  }
  return lines;
}

vector<string> south(vector<string> lines) {
  for (int i = lines.size() - 1; i >= 0; i--) {
    for (int j = 0; j < lines[i].size(); j++) {
      if (lines[i][j] == 'O') {
        int level = i;
        for (; level < lines.size() - 1; level++) {
          if (lines[level + 1][j] != '.') break;
        }
        lines[i][j] = '.';
        lines[level][j] = 'O';
      }
    }
  }
  return lines;
}

vector<string> west(vector<string> lines) {
  for (int j = 0; j < lines[0].size(); j++) {
    for (int i = 0; i < lines.size(); i++) {
      if (lines[i][j] == 'O') {
        int level = j;
        for (; level > 0; level--) {
          if (lines[i][level - 1] != '.') break;
        }
        lines[i][j] = '.';
        lines[i][level] = 'O';
      }
    }
  }
  return lines;
}

vector<string> east(vector<string> lines) {
  for (int j = lines[0].size() - 1; j >= 0; j--) {
    for (int i = 0; i < lines.size(); i++) {
      if (lines[i][j] == 'O') {
        int level = j;
        for (; level < lines[0].size() - 1; level++) {
          if (lines[i][level + 1] != '.') break;
        }
        lines[i][j] = '.';
        lines[i][level] = 'O';
      }
    }
  }
  return lines;
}

bool equal(vector<string> a, vector<string> b) {
  for (int i = 0; i < a.size(); i++) {
    if (a[i] != b[i]) return false;
  }
  return true;
}

int main() {
  ifstream fin("fourteen.in");
  vector<string> lines;
  string line;
  while (!fin.eof()) {
    getline(fin, line);
    lines.push_back(line);
  }
  vector<vector<string>> sets;
  sets.push_back(lines);
  int first;
  do {
    lines = east(south(west(north(lines))));
    for (int i = 0; i < sets.size(); i++) {
      if (equal(sets[i], lines)) {
        first = i;
        goto OUT;
      }
    }
    sets.push_back(lines);
  } while (true);
  OUT:
  int pos = (1000000000 - first) % (sets.size() - first) + first;
  lines = sets[pos];
  int sum = 0;
  for (int i = 0; i < lines.size(); i++) {
    for (int j = 0; j < lines[i].size(); j++) {
      if (lines[i][j] == 'O') sum += lines.size() - i;
    }
  }
  cout << sum << "\n";
}