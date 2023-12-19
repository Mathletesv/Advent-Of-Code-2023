#include <bits/stdc++.h>

using namespace std;

int main() {
  ifstream fin("eighteen.in");
  long long x = 0;
  long long y = 0;
  string color;
  char dir;
  long long meters;
  vector<pair<int, int>> coords;
  coords.push_back({0, 0});
  long long edges = 0;
  while (!fin.eof()) {
    fin >> dir >> meters >> color;
    edges += meters;
    x += (dir == 'R' ? meters : dir == 'L' ? -meters : 0);
    y += (dir == 'D' ? meters : dir == 'U' ? -meters : 0);
    coords.push_back({x, y});
  }
  int N = coords.size();
  coords.push_back({0, 0});
  long long area = 0;
  for (int i = 0; i < N; i++) {
    area += coords[i].first * coords[i + 1].second - coords[i].second * coords[i + 1].first;
  }
  area = area / 2;
  long long inner = (area - edges / 2 + 1);
  cout << edges + inner << "\n";
}