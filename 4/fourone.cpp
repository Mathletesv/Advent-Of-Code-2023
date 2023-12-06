#include <bits/stdc++.h>

using namespace std;

int main() {
  ifstream fin("four.in");
  int points = 0;
  string next;
  vector<int> winning;
  vector<int> numbers;
  fin >> next;
  while (!fin.eof()) {
    fin >> next >> next;
    winning.clear();
    numbers.clear();
    while (next != "|") {
      winning.push_back(stoi(next));
      fin >> next;
    }
    fin >> next;
    while (next != "Card" && !fin.eof()) {
      numbers.push_back(stoi(next));
      fin >> next;
    }
    int count = 0;
    for (int i = 0; i < winning.size(); i++) {
      for (int j = 0; j < numbers.size(); j++) {
        if (winning[i] == numbers[j]) {
          count++;
        }
      }
    }
    if (count > 0) points += pow(2, count - 1);
  }
  cout << points << "\n";
}