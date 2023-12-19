#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Part {
  ll x, m, a, s;
  Part(string str) {
    string x_str = "";
    string m_str = "";
    string a_str = "";
    string s_str = "";
    int index = 3;
    int start = index;
    while (str[index] != ',') {
      index++;
    }
    x_str = str.substr(start, (index - start));
    index += 3;
    start = index;
    while (str[index] != ',') {
      index++;
    }
    m_str = str.substr(start, (index - start));
    index += 3;
    start = index;
    while (str[index] != ',') {
      index++;
    }
    a_str = str.substr(start, (index - start));
    index += 3;
    start = index;
    while (str[index] != ',') {
      index++;
    }
    s_str = str.substr(start, (index - start));
    x = stoll(x_str);
    m = stoll(m_str);
    a = stoll(a_str);
    s = stoll(s_str);
  }

  ll sum() {
    return x + m + a + s;
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

  string run(Part part) {
    ll value;
    if (category == 'x') value = part.x;
    else if (category == 'm') value = part.m;
    else if (category == 'a') value = part.a;
    else value = part.s;
    if (oper && value > num) return result;
    if (!oper && value < num) return result;
    return "-1";
  }
};

struct Condition {
  vector<Check> checks;
  string else_c;
  init(string str) {
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

  string run(Part part) {
    string result;
    for (int i = 0; i < checks.size(); i++) {
      result = checks[i].run(part);
      if (result == "-1") continue;
      return result;
    }
    return else_c;
  }
};

int main() {
  ifstream fin("nineteen.in");
  vector<Part> parts;
  map<string, Condition> conditions;
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
  while (!fin.eof()) {
    getline(fin, line);
    parts.push_back(Part(line));
  }
  ll sum = 0;
  for (int i = 0; i < parts.size(); i++) {
    string current = "in";
    while (true) {
      current = conditions[current].run(parts[i]);
      if (current == "A") {
        sum += parts[i].sum();
        break;
      }
      else if (current == "R") {
        break;
      }
    }
  }
  cout << sum << "\n";
}