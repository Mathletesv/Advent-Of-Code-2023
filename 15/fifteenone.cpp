#include <bits/stdc++.h>

using namespace std;

int main() {
  ifstream fin("fifteen.in");
  string line;
  fin >> line;
  int sum = 0;
  for (int i = 0; i < line.size(); i++) {
    int j = i;
    int current = 0;
    while (j < line.size() && line[j] != ',') {
      current += int(line[j]);
      current *= 17;
      current %= 256;
      j++;
    }
    i = j;
    sum += current;
  }
  cout << sum << "\n";
}