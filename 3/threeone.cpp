#include <bits/stdc++.h>

using namespace std;

int main() {
  ifstream fin("three.in");
  string line;
  vector<string> lines;
  while (!fin.eof()) {
    getline(fin, line);
    lines.push_back(line);
  }
  int sum = 0;
  for (int i = 0; i < lines.size(); i++) {
    line = lines[i];
    for (int j = 0; j < line.length(); j++) {
      if (line[j] >= '0' && line[j] <= '9') {
        string numStr = "";
        int start = j;
        while (line[j] >= '0' && line[j] <= '9') {
          numStr += line[j];
          j++;
        }
        int end = j - 1;
        if (i != 0) {
          for (int k = max(0, start - 1); k < min(end + 2, (int) (line.length() - 1)); k++) {
            if (lines[i - 1][k] != '.' && (lines[i - 1][k] < '0' || lines[i - 1][k] > '9')) {
              sum += stoi(numStr);
              goto NEXT;
            }
          }
        }
        if (i != lines.size() - 1) {
          for (int k = max(0, start - 1); k < min(end + 2, (int) (line.length() - 1)); k++) {
            if (lines[i + 1][k] != '.' && (lines[i + 1][k] < '0' || lines[i + 1][k] > '9')) {
              sum += stoi(numStr);
              goto NEXT;
            }
          }
        }
        if (start != 0 && line[start - 1] != '.' && (line[start - 1] < '0' || line[start - 1] > '9')) {
          sum += stoi(numStr);
          goto NEXT;
        }
        if (end != line.length() - 1 && line[end + 1] != '.' && (line[end + 1] < '0' || line[end + 1] > '9')) {
          sum += stoi(numStr);
          goto NEXT;
        }
      }
      NEXT: continue;
    }
    
  }
  cout << sum << "\n";
}