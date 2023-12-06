#include <bits/stdc++.h>

using namespace std;

int stringnum(string line, int i) {
  string three = line.substr(i, 3);
  string four = line.substr(i, 4);
  string five = line.substr(i, 5);
  if (three == "one") return 1;
  if (three == "two") return 2;
  if (three == "six") return 6;
  if (four == "zero") return 0;
  if (four == "four") return 4;
  if (four == "five") return 5;
  if (four == "nine") return 9;
  if (five == "three") return 3;
  if (five == "seven") return 7;
  if (five == "eight") return 8;
  return -1;
}

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
      else {
        int num = stringnum(line, i);
        if (num != -1) {
          if (first == -1) first = num;
          last = num;
        }
      }

    }
    sum += first * 10 + last;
  }
  cout << sum << "\n";
}