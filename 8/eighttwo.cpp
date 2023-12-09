#include <bits/stdc++.h>
#include <numeric>

using namespace std;

map<string, string> left_map;
map<string, string> right_map;

int main() {
  ifstream fin("eight.in");
  string instruct;
  fin >> instruct;
  string at, leftto, rightto;
  vector<string> currents;
  vector<int> cycles;
  while (!fin.eof()) {
    fin >> at >> leftto >> leftto >> rightto;
    leftto = leftto.substr(1, 3);
    rightto = rightto.substr(0, 3);
    if (at[2] == 'A') {
      currents.push_back(at);
      cycles.push_back(-1);
    }
    left_map[at] = leftto;
    right_map[at] = rightto;
  }
  long long steps = 0;
  int pos = 0;
  bool done = false;
  while (!done) {
    done = true;
    if (instruct[pos] == 'L') {
      for (int i = 0; i < currents.size(); i++) {
        if (cycles[i] != -1) continue;
        currents[i] = left_map[currents[i]];
        if (currents[i][2] != 'Z') done = false;
        else cycles[i] = (steps + 1)/307;
      }
    }
    else {
      for (int i = 0; i < currents.size(); i++) {
        if (cycles[i] != -1) continue;
        currents[i] = right_map[currents[i]];
        if (currents[i][2] != 'Z') done = false;
        else cycles[i] = (steps + 1)/307;
      }
    }
    pos++;
    if (pos == instruct.size()) pos = 0;
    steps++;
  }
  steps = 1;
  for (int i = 0; i < cycles.size(); i++) {
    steps = lcm(steps, cycles[i]);
  }
  cout << steps * instruct.size() << "\n";
}