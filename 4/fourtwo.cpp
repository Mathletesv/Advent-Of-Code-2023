#include <bits/stdc++.h>

using namespace std;

int main() {
  ifstream fin("four.in");
  int sum = 0;
  string next;
  vector<int> winning;
  vector<int> numbers;
  int counts[221];
  for (int i = 0; i < 221; i++) counts[i] = 1;
  fin >> next;
  int index = 1;
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
    sum += counts[index];
    index++;
    for (int i = index; i < index + count; i++) counts[i] += counts[index - 1];
  }
  cout << sum << "\n";
}