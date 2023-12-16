#include <bits/stdc++.h>

using namespace std;

struct state {
  int x, y, dir;
  state(int x, int y, int dir): x(x), y(y), dir(dir) {}
};

int main() {
  ifstream fin("sixteen.in");
  vector<string> grid;
  string line;
  while (!fin.eof()) {
    getline(fin, line);
    grid.push_back(line);
  }
  vector<vector<bool>> energized(grid.size(), vector<bool>(grid[0].size(), false));
  vector<vector<array<bool, 4>>> visited(grid.size(), vector<array<bool, 4>>(grid[0].size()));
  queue<state> bfs;
  bfs.push(state(0, 0, 1));
  while (!bfs.empty()) {
    state front = bfs.front();
    bfs.pop();
    if (front.x < 0 || front.y < 0 || front.x == grid[0].size() || front.y == grid.size()) continue;
    energized[front.y][front.x] = true;
    if (visited[front.y][front.x][front.dir]) continue;
    visited[front.y][front.x][front.dir] = true;
    if (grid[front.y][front.x] == '.') {
      if (front.dir == 0) front.y--;
      else if (front.dir == 1) front.x++;
      else if (front.dir == 2) front.y++;
      else front.x--;
      bfs.push(front);
    }
    else if (grid[front.y][front.x] == '|') {
      if (front.dir == 0) front.y--;
      else if (front.dir == 2) front.y++;
      else {
        state second = state(front.x, front.y - 1, 0);
        front = state(front.x, front.y + 1, 2);
        bfs.push(second);
      }
      bfs.push(front);
    }
    else if (grid[front.y][front.x] == '-') {
      if (front.dir == 1) front.x++;
      else if (front.dir == 3) front.x--;
      else {
        state second = state(front.x + 1, front.y, 1);
        front = state(front.x - 1, front.y, 3);
        bfs.push(second);
      }
      bfs.push(front);
    }
    else if (grid[front.y][front.x] == '/') {
      if (front.dir == 0) {
        front.dir = 1;
        front.x++;
      }
      else if (front.dir == 1) {
        front.dir = 0;
        front.y--;
      }
      else if (front.dir == 2) {
        front.dir = 3;
        front.x--;
      }
      else {
        front.dir = 2;
        front.y++;
      }
      bfs.push(front);
    }
    else if (grid[front.y][front.x] == '\\') {
      if (front.dir == 0) {
        front.dir = 3;
        front.x--;
      }
      else if (front.dir == 3) {
        front.dir = 0;
        front.y--;
      }
      else if (front.dir == 2) {
        front.dir = 1;
        front.x++;
      }
      else {
        front.dir = 2;
        front.y++;
      }
      bfs.push(front);
    }
  }

  int count = 0;
  for (int i = 0; i < energized.size(); i++) {
    for (int j = 0; j < energized[i].size(); j++) {
      if (energized[i][j]) count++;
    }
  }
  cout << count << "\n";
}