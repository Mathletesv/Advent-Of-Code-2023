#include <bits/stdc++.h>

using namespace std;

struct Module {
  vector<string> targets;
  map<string, bool> inputs;
  int type;
  bool on = false;

  int pulse(int in) {
    if (type == 0) return in;
    if (type == 1) {
      if (in == 1) return 2;
      if (in == 0) on = !on;
      return on;
    }
    if (type == 2) {
      for (const auto &m : inputs) {
        if (m.second == false) return 1;
      }
      return 0;
    }
    return 2;
  }
};

int main() {
  ifstream fin("twenty.in");
  map<string, Module> modules;

  string line, name, next;
  while (!fin.eof()) {
    getline(fin, line);
    stringstream parser(line);
    Module m;
    parser >> name;
    m.type = 0;
    if (name != "broadcaster") {
      m.type = name[0] == '%' ? 1 : 2;
      name = name.substr(1);
    }
    parser >> next >> next;
    while (parser) {
      if (next[next.size() - 1] == ',') next = next.substr(0, next.size() - 1);
      m.targets.push_back(next);
      parser >> next;
    }
    modules[name] = m;
  }
  for (const auto &m : modules) {
    string name = m.first;
    Module mod = m.second;
    for (int i = 0; i < mod.targets.size(); i++) {
      if (modules[mod.targets[i]].type == 2) {
        modules[mod.targets[i]].inputs[name] = false;
      }
    } 
  }
  vector<int> iterations;
  long long low = 0;
  long long high = 0;
  for (int i = 0; i < 1000; i++) {
    queue<pair<string, int>> pulses;
    pulses.push({"broadcaster", 0});
    while (!pulses.empty()) {
      pair<string, int> pulse = pulses.front();
      //cout << pulse.second << "\n";
      if (pulse.second == 0) low++;
      else high++;
      pulses.pop();
      int next = modules[pulse.first].pulse(pulse.second);
      if (next == 2) continue;
      for (int i = 0; i < modules[pulse.first].targets.size(); i++) {
        string target = modules[pulse.first].targets[i];
        if (modules[target].type == 2) {
          modules[target].inputs[pulse.first] = next;
        }
        pulses.push({target, next});
      }
    }
  }
  cout << low << " " << high << "\n";
  cout << low * high << "\n";
}