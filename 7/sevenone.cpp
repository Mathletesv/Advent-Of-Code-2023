#include <bits/stdc++.h>

using namespace std;

struct Hand {
  string hand;
  int bid;
  int strength;
};

Hand create(string hand, int bid) {
  Hand h;
  h.hand = hand;
  h.bid = bid;
  string sorted = hand;
  sort(sorted.begin(), sorted.end());
  if (sorted[0] == sorted[1] && sorted[1] == sorted[2] && sorted[2] == sorted[3] && sorted[3] == sorted[4]) h.strength = 6;
  else if (sorted[0] == sorted[1] && sorted[1] == sorted[2] && sorted[2] == sorted[3]) h.strength = 5;
  else if (sorted[1] == sorted[2] && sorted[2] == sorted[3] && sorted[3] == sorted[4]) h.strength = 5;
  else if (sorted[0] == sorted[1] && sorted[1] == sorted[2] && sorted[3] == sorted[4]) h.strength = 4;
  else if (sorted[0] == sorted[1] && sorted[2] == sorted[3] && sorted[3] == sorted[4]) h.strength = 4;
  else if (sorted[0] == sorted[1] && sorted[1] == sorted[2]) h.strength = 3;
  else if (sorted[1] == sorted[2] && sorted[2] == sorted[3]) h.strength = 3;
  else if (sorted[2] == sorted[3] && sorted[3] == sorted[4]) h.strength = 3;
  else if (sorted[0] == sorted[1] && sorted[2] == sorted[3]) h.strength = 2;
  else if (sorted[0] == sorted[1] && sorted[3] == sorted[4]) h.strength = 2;
  else if (sorted[1] == sorted[2] && sorted[3] == sorted[4]) h.strength = 2;
  else if (sorted[0] == sorted[1]) h.strength = 1;
  else if (sorted[1] == sorted[2]) h.strength = 1;
  else if (sorted[2] == sorted[3]) h.strength = 1;
  else if (sorted[3] == sorted[4]) h.strength = 1;
  else h.strength = 0;
  return h;
}

map<char, int> m = {{'A', 14}, {'K', 13}, {'Q', 12}, {'J', 11}, {'T', 10}, {'9', 9}, {'8', 8}, {'7', 7}, {'6', 6}, {'5', 5}, {'4', 4}, {'3', 3}, {'2', 2}};
struct cmp {
  bool operator() (Hand lhs, Hand rhs) const {
    if (lhs.strength == rhs.strength) {
      for (int i = 0; i < 5; i++) {
        if (lhs.hand[i] != rhs.hand[i]) {
          return m[lhs.hand[i]] < m[rhs.hand[i]];
        }
      }
      cout << "ERR" << "\n";
      return false;
    };
    return lhs.strength < rhs.strength;
  }
};

int main() {
  ifstream fin("seven.in");
  string hand;
  int bid;
  set<Hand, cmp> hands;
  while (!fin.eof()) {
    fin >> hand >> bid;
    hands.insert(create(hand, bid));
  }
  int sum = 0;
  int i = 1;
  for (auto it = hands.begin(); it != hands.end(); it++) {
    sum += it->bid * i;
    i++;
  }
  cout << sum << "\n";
}