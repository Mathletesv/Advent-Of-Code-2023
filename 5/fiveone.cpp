#include <bits/stdc++.h>

using namespace std;

int main() {
  ifstream fin("five.in");
  vector<long long> start;
  vector<long long> end;
  string next;
  fin >> next >> next;
  while (next != "seed-to-soil") {
    start.push_back(stoll(next));
    end.push_back(0);
    fin >> next;
  }
  long long destination, source, range;
  while (!fin.eof()) {
    cout << next << "\n";
    fin >> next >> next;
    do {
      destination = stoll(next);
      fin >> source >> range;
      for (int i = 0; i < start.size(); i++) {
        if (start[i] > source && start[i] < source + range) {
          end[i] = destination + start[i] - source;
        }
      }
      fin >> next;
    } while (!fin.eof() && next.find("to") == std::string::npos);
    for (int i = 0; i < start.size(); i++) start[i] = end[i];
  }
  long long min = LONG_MAX;
  for (int i = 0; i < end.size(); i++) {
    if (end[i] < min) min = end[i];
  }
  cout << min << "\n";
}