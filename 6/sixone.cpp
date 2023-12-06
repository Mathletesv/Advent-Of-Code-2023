#include <bits/stdc++.h>

using namespace std;

int solve(double time, double distance) {
  int min = floor((-time + sqrt(time * time - 4.0 * distance)) / -2.0 + 1);
  int max = ceil((-time - sqrt(time * time - 4.0 * distance)) / -2.0 - 1);
  return max - min + 1;
}

int main() {
  ifstream fin("six.in");
  string next;
  fin >> next >> next;
  vector<int> times;
  vector<int> distances;
  while (next != "Distance:") {
    times.push_back(stoi(next));
    fin >> next;
  }
  while (!fin.eof()) {
    fin >> next;
    distances.push_back(stoi(next));
  }
  int wins = 1;
  for (int i = 0; i < times.size(); i++) {
    wins *= solve(times[i], distances[i]);
  }
  cout << wins << "\n";
}