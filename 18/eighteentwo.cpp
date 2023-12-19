#include <bits/stdc++.h>

using namespace std;

long long extract(string color) {
  int pos = 1;
  long long num = 0;
  long long factor = 1;
  while (color[pos] != '#') {
    if (color[pos] >= '0' && color[pos] <= '9') {
      num += (color[pos] - '0') * factor;
    }
    else {
      num += (10 + color[pos] - 'a') * factor;
    }
    factor *= 16;
    pos++;
  }
  return num;
}

int main() {
  ifstream fin("eighteen.in");
  long long x = 0;
  long long y = 0;
  string color;
  char dir;
  long long meters;
  vector<pair<long long, long long>> coords;
  coords.push_back({0, 0});
  long long edges = 0;
  while (!fin.eof()) {
    fin >> dir >> meters >> color;
    color = color.substr(0, color.size() - 1);
    reverse(color.begin(), color.end());
    dir = (color[0] == '0' ? 'R' : color[0] == '1' ? 'D' : color[0] == '2' ? 'L' : 'U');
    meters = extract(color);
    edges += meters;
    x += (dir == 'R' ? meters : dir == 'L' ? -meters : 0);
    y += (dir == 'D' ? meters : dir == 'U' ? -meters : 0);
    coords.push_back({x, y});
  }
  int N = coords.size() - 1;
  long long area = 0;
  for (int i = 0; i < N; i++) {
    area += (coords[i].first + coords[i + 1].first) * (coords[i + 1].second - coords[i].second);
  }
  area = abs(area);
  area = area / 2;
  long long inner = (area - edges / 2 + 1);
  cout << edges + inner << "\n";
}