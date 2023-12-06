#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct Interval {
  ll start;
  ll range;
  bool overlaps(Interval other) {
    return start < other.start + other.range && start + range > other.start;
  }
  Interval split(Interval modifier, ll offset) {
    Interval created;
    if (modifier.start < start && modifier.start + modifier.range > start + range) {
      created.start = modifier.start;
      created.range = modifier.range;
      this->range = 0;
    }
    else if (modifier.start > start) {
      created.start = modifier.start;
      created.range = range + start - modifier.start;
      this->range = modifier.start - start;
    }
    else {
      created.start = start;
      created.range = modifier.range + modifier.start - start;
      this->range = range + this->start - (modifier.start + modifier.range);
      this->start = modifier.start + modifier.range;
    }
    created.start += offset;
    return created;
  }
};

Interval create(ll start, ll range) {
  Interval created;
  created.start = start;
  created.range = range;
  return created;
}

array<map<ll, pair<ll, ll>, std::greater<ll>>, 7> maps;

int main() {
  ifstream fin("five.in");
  vector<Interval> start;
  string next;
  ll range;
  fin >> next >> next;
  while (next != "seed-to-soil") {
    cout << next << "\n";
    fin >> range;
    start.push_back(create(stoll(next), range));
    fin >> next;
  }
  ll destination, source;
  int index = 0;
  while (!fin.eof()) {
    cout << next << "\n";
    fin >> next >> next;
    do {
      destination = stoll(next);
      fin >> source >> range;
      maps[index][source] = {destination, range};
      fin >> next;
    } while (!fin.eof() && next.find("to") == std::string::npos);
    cout << maps[index].size() << "\n";
    index++;
  }
  ll min = LLONG_MAX;
  for (int i = 0; i < start.size(); i++) {
    cout << i << "\n";
    for (ll num = start[i].start; num < start[i].start + start[i].range; num++) {
      ll value = num;
      for (int j = 0; j < 7; j++) {
        auto it = maps[j].lower_bound(value);
        // if (value < it->first) {
        //   cout << "ERROR " << value << " " << it->first << " " << num << " " << j << "\n";
        // }
        if (value > it->first && value < it->first + (it->second).second) {
          value = (it->second).first + value - it->first;
        }
      }
      if (value < min) {
        cout << value << "\n";
        min = value;
      }
    }
  }
  cout << min << "\n";
}