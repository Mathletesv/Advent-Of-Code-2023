#include <bits/stdc++.h>

using namespace std;

int main() {
  ifstream fin("nine.in");
  long long extrapolated = 0;
  string line;
  vector<int> original;
  while (!fin.eof()) {
    original.clear();
    getline(fin, line);
    stringstream ss(line);
    int next;
    while (ss.rdbuf()->in_avail()) {
      ss >> next;
      original.push_back(next);
    }
    vector<vector<int>> diffs;
    diffs.push_back(original);
    while (true) {
      bool zero = true;
      vector<int> lower;
      vector<int> last = diffs[diffs.size() - 1];
      for (int i = 0; i < last.size() - 1; i++) {
        if (last[i + 1] - last[i] != 0) zero = false;
        lower.push_back(last[i + 1] - last[i]);
      }
      diffs.push_back(lower);
      if (zero) {
        diffs[diffs.size() - 1].push_back(0);
        for (int i = diffs.size() - 2; i >= 0; i--) {
          diffs[i].push_back(diffs[i][diffs[i].size() - 1] + diffs[i + 1][diffs[i + 1].size() - 1]);
        }
        extrapolated += diffs[0][diffs[0].size() - 1];
        break;
      }
    }
  }
  cout << extrapolated << "\n";
}