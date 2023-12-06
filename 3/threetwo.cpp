#include <bits/stdc++.h>

using namespace std;

bool isNum(char c) {
  return c >= '0' && c <= '9';
}

int getNum(string line, int index) {
  if (!isNum(line[index])) return -1;
  while (index > 0 && isNum(line[index - 1])) index--;
  string numStr = "";
  while (isNum(line[index]) && index < line.length()) {
    numStr += line[index];
    index++;
  }
  return stoi(numStr);
}

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
      if (line[j] == '*') {
        int one = -1;
        int two = -1;
        if (j != 0 && isNum(line[j - 1])) {
          one = getNum(line, j - 1);
        }
        if (j != line.length() - 1 && isNum(line[j + 1])) {
          if (one == -1) one = getNum(line, j + 1);
          else two = getNum(line, j + 1);
        }
        if (i != 0) {
          int before, middle, after;
          before = middle = after = -1;
          if (j != 0) before = getNum(lines[i - 1], j - 1);
          middle = getNum(lines[i - 1], j);
          if (j != line.length() - 1) after = getNum(lines[i - 1], j + 1);
          if (middle == -1 && before != -1 && after != -1) {
            if (one != -1 || two != -1) continue;
            one = before;
            two = after;
          }
          else if (middle != -1 || before != -1 || after != -1) {
            before = max(before, max(middle, after));
            if (one == -1) one = before;
            else if (two == -1) two = before;
            else continue;
          } 
        }
        if (i != lines.size() - 1) {
          int before, middle, after;
          before = middle = after = -1;
          if (j != 0) before = getNum(lines[i + 1], j - 1);
          middle = getNum(lines[i + 1], j);
          if (j != line.length() - 1) after = getNum(lines[i + 1], j + 1);
          if (middle == -1 && before != -1 && after != -1) {
            if (one != -1 || two != -1) continue;
            one = before;
            two = after;
          }
          else if (middle != -1 || before != -1 || after != -1) {
            before = max(before, max(middle, after));
            if (one == -1) one = before;
            else if (two == -1) two = before;
            else continue;
          } 
        }
        cout << one << " " << two << "\n";
        if (one != -1 && two != -1) sum += one * two;
      }
      
    }
    
  }
  cout << sum << "\n";
}