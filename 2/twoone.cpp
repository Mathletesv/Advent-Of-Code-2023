#include <bits/stdc++.h>

using namespace std;

int main() {
  ifstream fin("two.in");
  string line;
  int game = 0;
  int sum = 0;
  while (!fin.eof()) {
    getline(fin, line);
    game++;
    bool started = false;
    int index = 0;
    bool possible = true;
    for (int i = 0; i < line.length(); i++) {
      if (started == false) {
        if (line[i] == ':') {
          started = true;
          i += 2;
        }
        else continue;
      }
      string numStr = "";
      while (line[i] != ' ') numStr += line[i++];
      int num = stoi(numStr);
      i++;
      string color = "";
      while (i < line.length() && line[i] != ',' && line[i] != ';') {
        color += line[i];
        i++;
      }
      i++;
      if (color == "red" && num > 12) possible = false;
      else if (color == "green" && num > 13) possible = false;
      else if (color == "blue" && num > 14) possible = false;
      if (!possible) break;
    }
    if (possible) sum += game;
  }
  cout << sum << "\n";
}