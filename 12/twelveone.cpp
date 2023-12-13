#include <bits/stdc++.h>

using namespace std;

int dfs(string current, vector<int> springs, int index) {
  //cout << current << " " << index << "\n";
  int springs_i = 0;
  for (int i = 0; i < current.size(); i++) {
    if (current[i] == '#') {
      if (springs_i == springs.size()) return 0;
      int count = 0;
      while (current[i] == '#') {
        i++;
        count++;
      }
      if (current[i] == '?' && count > springs[springs_i]) return 0;
      if (current[i] == '?') break;
      if (count != springs[springs_i]) return 0;
      springs_i++;
    } 
    else if (current[i] == '?') break;
    else if (i >= current.size() - 1) return springs_i == springs.size();
  }
  if (index >= current.size()) return springs_i == springs.size();
  if (current[index] == '?') {
    int sum = 0;
    current[index] = '.';
    sum += dfs(current, springs, index + 1);
    current[index] = '#';
    sum += dfs(current, springs, index + 1);
    return sum;
  }
  else return dfs(current, springs, index + 1);
}

int solve(string line) {
  string data = line.substr(0, line.find(" "));
  string damaged = line.substr(line.find(" ") + 1);
  vector<int> springs;
  while (damaged.find(",") != std::string::npos) {
    string num = damaged.substr(0, damaged.find(","));
    springs.push_back(stoi(num));
    damaged.erase(0, damaged.find(",") + 1);
  }
  springs.push_back(stoi(damaged));
  return dfs(data, springs, 0);
}

int main() {
  ifstream fin("twelve.in");
  string line;
  int sum = 0;
  while (!fin.eof()) {
    getline(fin, line);
    sum += solve(line);
  }
  cout << sum << "\n";
}