#include <bits/stdc++.h>

using namespace std;

int main() {
  ifstream fin("eleven.in");
  vector<int> x_coords;
  vector<int> y_coords;
  string line;
  int y = 0;
  while (!fin.eof()) {
    getline(fin, line);
    for (int i = 0; i < line.size(); i++) {
      if (line[i] == '#') {
        x_coords.push_back(i);
        y_coords.push_back(y);
      }
    }
    y++;
  }
  sort(x_coords.begin(), x_coords.end());
  sort(y_coords.begin(), y_coords.end());
  long long sum = 0;
  int x_pos = 0;
  int x_pos_last = 0;
  int x_last = -1;
  for (int i = 0; i < x_coords.size(); i++) {
    x_pos += x_coords[i] - x_last;
    if (x_coords[i] - x_last > 1) x_pos += x_coords[i] - x_last - 1;
    sum -= x_pos * (x_coords.size() - i - 1);
    sum += x_pos * i;
    x_pos_last = x_pos;
    x_last = x_coords[i];
  }
  int y_pos = 0;
  int y_pos_last = 0;
  int y_last = -1;
  for (int i = 0; i < y_coords.size(); i++) {
    y_pos += y_coords[i] - y_last;
    if (y_coords[i] - y_last > 1) y_pos += y_coords[i] - y_last - 1;
    sum -= y_pos * (y_coords.size() - i - 1);
    sum += y_pos * i;
    y_pos_last = y_pos;
    y_last = y_coords[i];
  }
  cout << sum << "\n";
}