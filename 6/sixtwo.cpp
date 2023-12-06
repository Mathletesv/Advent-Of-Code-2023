#include <bits/stdc++.h>

using namespace std;

int solve(long long time, long long distance) {
  int ways = 0;
  for (int i = 0; i <= time; i++) {
    if (i * (time - i) > distance) ways++;
  }
  return ways;
}

int main() {
  ifstream fin("six.in");
  string next;
  fin >> next >> next;
  string time = "";
  string distance = "";
  while (next != "Distance:") {
    time += next;
    fin >> next;
  }
  while (!fin.eof()) {
    fin >> next;
    distance += next;
  }
  cout << solve(stoll(time), stoll(distance)) << "\n";
}