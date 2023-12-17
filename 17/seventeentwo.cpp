#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;

struct state {
  int x, y, loss, dir, straight;
  state(int x, int y, int loss, int dir, int straight): x(x), y(y), loss(loss), dir(dir), straight(straight) {}
};

struct square {
  int minheat[10][4];
  square() {
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 4; j++) {
        minheat[i][j] = INF;
      }
    }
  }
  bool update(int straight, int dir, int heat) {
    if (heat < minheat[straight - 1][dir]) {
      minheat[straight - 1][dir] = heat;
      return true;
    }
    return false;
  }
  int best() {
    int current = INF;
    for (int i = 3; i < 10; i++) {
      for (int j = 0; j < 4; j++) {
        current = min(current, minheat[i][j]);
      }
    }
    return current;
  }
};

int ctoi(char c) {
  return c - '0';
}

int main() {
  ifstream fin("seventeen.in");
  vector<string> grid;
  string line;
  while (!fin.eof()) {
    fin >> line;
    grid.push_back(line);
  }
  vector<vector<square>> heatloss(grid.size(), vector<square>(grid[0].size(), square()));
  queue<state> bfs;
  bfs.push(state(1, 0, 0, 1, 1));
  bfs.push(state(0, 1, 0, 2, 1));
  while (!bfs.empty()) {
    //cout << bfs.size() << "\n";
    state front = bfs.front();
    bfs.pop();
    if (front.straight > 10 || front.x < 0 || front.y < 0 || front.y >= grid.size() || front.x >= grid[0].size()) continue;
    front.loss += ctoi(grid[front.y][front.x]);
    if (!heatloss[front.y][front.x].update(front.straight, front.dir, front.loss)) continue;
    if (front.straight < 4) {
      bfs.push(state(front.x + ((front.dir - 2) % 2) * -1, front.y + (front.dir - 1) % 2, front.loss, front.dir, front.straight + 1));
      continue;
    }
    if (front.dir != 0) {
      bfs.push(state(front.x, front.y + 1, front.loss, 2, front.dir == 2 ? front.straight + 1 : 1));
    }
    if (front.dir != 2) {
      bfs.push(state(front.x, front.y - 1, front.loss, 0, front.dir == 0 ? front.straight + 1 : 1));
    }
    if (front.dir != 1) {
      bfs.push(state(front.x - 1, front.y, front.loss, 3, front.dir == 3 ? front.straight + 1 : 1));
    }
    if (front.dir != 3) {
      bfs.push(state(front.x + 1, front.y, front.loss, 1, front.dir == 1 ? front.straight + 1 : 1));
    }
  }
  cout << heatloss[grid.size() - 1][grid[0].size() - 1].best() << "\n";
}