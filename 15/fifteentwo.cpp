#include <bits/stdc++.h>

using namespace std;

array<list<pair<string, int>>, 256> boxes;

int main() {
  ifstream fin("fifteen.in");
  string line;
  fin >> line;
  for (int i = 0; i < line.size(); i++) {
    int j = i;
    int box = 0;
    string label = "";
    while (j < line.size() && line[j] != '=' && line[j] != '-') {
      label += line[j];
      box += int(line[j]);
      box *= 17;
      box %= 256;
      j++;
    }
    char type = line[j];
    j++;
    if (type == '=') {
      j += 1;
      int focal = line[j - 1] - '0';
      for (auto &current : boxes[box]) {
        if (current.first == label) {
          current.second = focal;
          goto OUT;
        }
      }
      boxes[box].push_back({label, focal});
      OUT:;
    }
    else {
      for (auto it = boxes[box].begin(); it != boxes[box].end(); it++) {
        if (it->first == label) {
          boxes[box].erase(it);
          break;
        }
      }
    }
    i = j;
  }
  int power = 0;
  for (int i = 0; i < boxes.size(); i++) {
    int j = 1;
    //cout << i << " " << boxes[i].size() << "\n";
    for (auto lens : boxes[i]) {
      power += (i + 1) * j * lens.second;
      j++;
    }
  }
  cout << power << "\n";
}