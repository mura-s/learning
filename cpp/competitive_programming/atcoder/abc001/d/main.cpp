#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

pair<int, int> parse(string &line) {
  int s = stoi(line.substr(0, 4));
  int e = stoi(line.substr(5, 4));

  int s_last = s % 10;
  if (0 < s_last && s_last < 5) {
    s -= s_last;
  } else if (5 < s_last && s_last <= 9) {
    s -= (s_last - 5);
  }

  int e_last = e % 100;
  if (55 < e_last && e_last <= 59) {
    e += 100 - e_last;
  } else {
    e_last %= 10;
    if (0 < e_last && e_last < 5) {
      e += 5 - e_last;
    } else if (5 < e_last && e_last <= 9) {
      e += 10 - e_last;
    }
  }

  return make_pair(s, e);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  vector<pair<int, int>> se;
  for (int i = 0; i < N; i++) {
    string line;
    cin >> line;
    se.push_back(parse(line));
  }

  sort(se.begin(), se.end());

  vector<pair<int, int>> ans;
  pair<int, int> cur_range = se[0];
  for (int i = 1; i < se.size(); i++) {
    if (se[i].first <= cur_range.second && cur_range.second < se[i].second) {
      cur_range.second = se[i].second;
    } else if (cur_range.second < se[i].first) {
      ans.push_back(cur_range);
      cur_range = se[i];
    }
  }
  ans.push_back(cur_range);

  for (auto &e : ans) {
    cout << setfill('0') << setw(4) << e.first;
    cout << '-';
    cout << setfill('0') << setw(4) << e.second << endl;
  }
  return 0;
}