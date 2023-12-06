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
    int red = 0;
    int blue = 0;
    int green = 0;
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
      if (color == "red" && num > red) red = num;
      else if (color == "green" && num > green) green = num;
      else if (color == "blue" && num > blue) blue = num;
    }
    sum += red * green * blue;
  }
  cout << sum << "\n";
}