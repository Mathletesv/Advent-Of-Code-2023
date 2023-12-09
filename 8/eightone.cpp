#include <bits/stdc++.h>

using namespace std;

map<string, string> left_map;
map<string, string> right_map;

int main() {
  ifstream fin("eight.in");
  string instruct;
  fin >> instruct;
  string at, leftto, rightto;
  while (!fin.eof()) {
    fin >> at >> leftto >> leftto >> rightto;
    leftto = leftto.substr(1, 3);
    rightto = rightto.substr(0, 3);
    left_map[at] = leftto;
    right_map[at] = rightto;
  }
  int steps = 0;
  string current = "AAA";
  int pos = 0;
  while (current != "ZZZ") {
    if (instruct[pos] == 'L') current = left_map[current];
    else current = right_map[current];
    pos++;
    if (pos == instruct.size()) pos = 0;
    steps++;
  }
  cout << steps << "\n";
}