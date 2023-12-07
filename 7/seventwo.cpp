#include <bits/stdc++.h>

using namespace std;

struct Hand {
  string hand;
  int bid;
  int strength;
};

int test(string sorted) {
  sort(sorted.begin(), sorted.end());
  if (sorted[0] == sorted[1] && sorted[1] == sorted[2] && sorted[2] == sorted[3] && sorted[3] == sorted[4]) return 6;
  else if (sorted[0] == sorted[1] && sorted[1] == sorted[2] && sorted[2] == sorted[3]) return 5;
  else if (sorted[1] == sorted[2] && sorted[2] == sorted[3] && sorted[3] == sorted[4]) return 5;
  else if (sorted[0] == sorted[1] && sorted[1] == sorted[2] && sorted[3] == sorted[4]) return 4;
  else if (sorted[0] == sorted[1] && sorted[2] == sorted[3] && sorted[3] == sorted[4]) return 4;
  else if (sorted[0] == sorted[1] && sorted[1] == sorted[2]) return 3;
  else if (sorted[1] == sorted[2] && sorted[2] == sorted[3]) return 3;
  else if (sorted[2] == sorted[3] && sorted[3] == sorted[4]) return 3;
  else if (sorted[0] == sorted[1] && sorted[2] == sorted[3]) return 2;
  else if (sorted[0] == sorted[1] && sorted[3] == sorted[4]) return 2;
  else if (sorted[1] == sorted[2] && sorted[3] == sorted[4]) return 2;
  else if (sorted[0] == sorted[1]) return 1;
  else if (sorted[1] == sorted[2]) return 1;
  else if (sorted[2] == sorted[3]) return 1;
  else if (sorted[3] == sorted[4]) return 1;
  else return 0;
}

char jokers[12] = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'Q', 'K', 'A'};

Hand create(string hand, int bid) {
  Hand h;
  h.hand = hand;
  h.bid = bid;
  string sorted = hand;
  h.strength = 0;
  sort(sorted.begin(), sorted.end());
  if (sorted.find('J') != string::npos) {
    for (int i = 0; i < 12; i++) {
      string replaced = sorted;
      for (int j = 0; j < 5; j++) {
        if (replaced[j] == 'J') replaced[j] = jokers[i];
      }
      h.strength = max(h.strength, test(replaced));
    }
  }
  else {
    h.strength = test(sorted);
  }
  return h;
}

map<char, int> m = {{'A', 14}, {'K', 13}, {'Q', 12}, {'J', 1}, {'T', 10}, {'9', 9}, {'8', 8}, {'7', 7}, {'6', 6}, {'5', 5}, {'4', 4}, {'3', 3}, {'2', 2}};
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