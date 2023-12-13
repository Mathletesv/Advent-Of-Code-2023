#include <bits/stdc++.h>

using namespace std;

long long solve(string line) {
  string data = line.substr(0, line.find(" "));
  string damaged = line.substr(line.find(" ") + 1);
  vector<int> springs;
  while (damaged.find(",") != std::string::npos) {
    string num = damaged.substr(0, damaged.find(","));
    springs.push_back(stoi(num));
    damaged.erase(0, damaged.find(",") + 1);
  }
  springs.push_back(stoi(damaged));
  string long_data = data;
  for (int i = 0; i < 4; i++) long_data += "?" + data;
  int spring_count = springs.size();
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < spring_count; j++) {
      springs.push_back(springs[j]);
    }
  }
  data = long_data;
  data += '.';
  vector<vector<vector<long long>>> dp(data.size(), vector<vector<long long>>(springs.size() + 1, vector<long long>(16, 0)));
  if (data[0] == '.') dp[0][0][0] = 1;
  else if (data[0] == '#') dp[0][0][1] = 1;
  else {
    dp[0][0][0] = 1;
    dp[0][0][1] = 1;
  }
  for (int i = 1; i < data.size(); i++) {
    for (int j = 0; j <= springs.size(); j++) {
      if (j < springs.size() && (data[i] == '#' || data[i] == '?')) {
        for (int k = 1; k <= springs[j]; k++) {
          dp[i][j][k] += dp[i - 1][j][k - 1];
        }
      }
      if (data[i] == '.' || data[i] == '?') {
        if (j > 0) dp[i][j][0] += dp[i - 1][j - 1][springs[j - 1]];
        dp[i][j][0] += dp[i - 1][j][0];
      }
    }
  }
  return dp[data.size() - 1][springs.size()][0];
}

int main() {
  ifstream fin("twelve.in");
  string line;
  long long sum = 0;
  while (!fin.eof()) {
    getline(fin, line);
    sum += solve(line);
  }
  cout << sum << "\n";
}