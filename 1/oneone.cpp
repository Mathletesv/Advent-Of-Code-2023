#include <bits/stdc++.h>

using namespace std;

int main() {
  ifstream fin("one.in");
  string line;
  int sum = 0;
  while (getline(fin, line)) {
    int first = -1;
    int last = -1;
    for (int i = 0; i < line.size(); i++) {
      if (line[i] >= '0' && line[i] <= '9') {
        string num = "";
        num += line[i];
        if (first == -1) first = stoi(num);
        last = stoi(num);
      }
    }
    sum += first * 10 + last;
  }
  cout << sum << "\n";
}