#include <bits/stdc++.h>

using namespace std;

pair<int, int> next(pair<int, int> pos, pair<int, int> prev, char c) {
  if (c == '|') {
    return {pos.first, 2 * pos.second - prev.second};
  }
  else if (c == '-') {
    return {2 * pos.first - prev.first, pos.second};
  }
  else if (c == 'L') {
    if (pos.second != prev.second) return {pos.first + 1, pos.second};
    else return {pos.first, pos.second - 1};
  }
  else if (c == 'J') {
    if (pos.second != prev.second) return {pos.first - 1, pos.second};
    else return {pos.first, pos.second - 1};
  }
  else if (c == '7') {
    if (pos.second != prev.second) return {pos.first - 1, pos.second};
    else return {pos.first, pos.second + 1};
  }
  else if (c == 'F') {
    if (pos.second != prev.second) return {pos.first + 1, pos.second};
    else return {pos.first, pos.second + 1};
  }
  else {
    cout << pos.first << " " << pos.second << " " << c << "BAD";
    return {-1, -1};
  }
}

int main() {
  ifstream fin("ten.in");
  vector<string> lines;
  string line;
  int x, y;
  x = y = -1;
  while (!fin.eof()) {
    getline(fin, line);
    lines.push_back(line);
    if (x != -1) continue;
    for (int i = 0; i < line.size(); i++) {
      if (line[i] == 'S') {
        x = i;
        y = lines.size() - 1;
      }
    }
  }
  vector<pair<int, int>> last;
  vector<pair<int, int>> positions;
  if (lines[y][x - 1] != '|' && lines[y][x - 1] != 'J' && lines[y][x - 1] != '7') positions.push_back({x - 1, y});
  if (lines[y][x + 1] != '|' && lines[y][x + 1] != 'L' && lines[y][x + 1] != 'F') positions.push_back({x + 1, y});
  if (lines[y - 1][x] != '-' && lines[y - 1][x] != 'J' && lines[y - 1][x] != 'L') positions.push_back({x, y - 1});
  if (lines[y + 1][x] != '-' && lines[y + 1][x] != 'F' && lines[y + 1][x] != '7') positions.push_back({x, y + 1});
  for (int i = 0; i < positions.size(); i++) last.push_back({x, y});

  int steps = 1;
  int one, two;
  while (true) {
    for (int i = 0; i < positions.size(); i++) {
      pair<int, int> pos = positions[i];
      pair<int, int> prev = last[i];
      last[i] = pos;
      char c = lines[pos.second][pos.first];
      positions[i] = next(pos, prev, c);
    }
    steps++;
    for (int i = 0; i < positions.size(); i++) {
      for (int j = 0; j < positions.size(); j++) {
        if (i != j && positions[i].first == positions[j].first && positions[i].second == positions[j].second) {
          one = i;
          two = j;
          goto EXIT;
        }
      }
    }
  }

  EXIT:
  lines[y][x] = 'J'; // From Inspection Of S
  pair<int, int> pos = positions[one];
  pair<int, int> prev = last[one];
  char c = lines[pos.second][pos.first];
  double area = 0;
  pair<int, int> point = {pos.first, pos.second};
  do {
    last[one] = pos;
    positions[one] = next(pos, prev, c);
    pos = positions[one];
    prev = last[one];
    c = lines[pos.second][pos.first];
    if (c != '|' && c != '-') {
      area += (point.second + pos.second) * (point.first - pos.first);
      point = {pos.first, pos.second};
    }
  } while (pos.first != positions[two].first || pos.second != positions[two].second);
  area = area / 2;
  area = abs(area);
  cout << area - steps + 1 << "\n";
}