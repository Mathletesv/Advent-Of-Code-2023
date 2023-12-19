#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Part {
  ll x_max, m_max, a_max, s_max;
  ll x_min, m_min, a_min, s_min;

  bool valid() {
    return x_max > x_min + 1 && m_max > m_min + 1 && a_max > a_min + 1 && s_max > s_min + 1;
  }

  ll sum() {
    return (x_max - x_min - 1) * (m_max - m_min - 1) * (a_max - a_min - 1) * (s_max - s_min - 1);
  }

  void print() {
    cout << "mins: " << x_min << " " << m_min << " " << a_min << " " << s_min << "\n";
    cout << "maxs: " << x_max << " " << m_max << " " << a_max << " " << s_max << "\n"; 
  }
};

struct Check {
  char category;
  ll num;
  bool oper;
  string result;
  Check(string str) {
    category = str[0];
    oper = str[1] == '>';
    num = stoll(str.substr(2, str.find(':') - 2));
    result = str.substr(str.find(':') + 1);
    //cout << category << " " << oper << " " << num << " " << result << "\n";
  }

  Part squeeze(Part part, bool anti = false) {
    if ((oper && !anti) || (!oper && anti)) {
      if (category == 'x') part.x_min = max(part.x_min, num - anti);
      else if (category == 'm') part.m_min = max(part.m_min, num - anti);
      else if (category == 'a') part.a_min = max(part.a_min, num - anti);
      else part.s_min = max(part.s_min, num - anti);
    }
    else {
      if (category == 'x') part.x_max = min(part.x_max, num + anti);
      else if (category == 'm') part.m_max = min(part.m_max, num + anti);
      else if (category == 'a') part.a_max = min(part.a_max, num + anti);
      else part.s_max = min(part.s_max, num + anti);
    }
    return part;
  }
};

struct Condition {
  vector<Check> checks;
  string else_c;
  void init(string str) {
    //cout << str << "\n";
    str = str.substr(1, str.size() - 2);
    int pos = str.find(',');
    int old = 0;
    while (pos != string::npos) {
      checks.push_back(str.substr(old, pos - old));
      old = pos + 1;
      pos = str.find(',', pos + 1);
    }
    else_c = str.substr(old);
    //cout << else_c << "\n";
  }
};

map<string, Condition> conditions;

ll dfs(Part part, string cond) {
  if (cond == "R") return 0;
  if (cond == "A") return part.sum();
  if (!part.valid()) return 0;
  Condition condition = conditions[cond];
  ll sum = 0;
  for (int i = 0; i < condition.checks.size(); i++) {
    Check check = condition.checks[i];
    Part restricted = check.squeeze(part);
    sum += dfs(restricted, check.result);
    part = check.squeeze(part, true);
  }
  sum += dfs(part, condition.else_c);
  return sum;
}

int main() {
  ifstream fin("nineteen.in");
  string line;
  while (true) {
    getline(fin, line);
    if (line == "") break;
    string key = line.substr(0, line.find('{'));
    string rest = line.substr(line.find('{'));
    //cout << key << " " << rest << "\n";
    Condition to_add;
    to_add.init(rest);
    conditions[key] = to_add;
  }
  Part part;
  part.x_max = part.m_max = part.a_max = part.s_max = 4001;
  part.x_min = part.m_min = part.a_min = part.s_min = 0;
  ll sum = dfs(part, "in");
  cout << sum << "\n";
}