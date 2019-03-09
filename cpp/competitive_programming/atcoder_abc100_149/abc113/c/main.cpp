#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, M;
  cin >> N >> M;
  vector<pair<int, int>> pys;
  vector<vector<int>> mp(N + 1);
  for (int i = 0; i < M; i++) {
    int p, y;
    cin >> p >> y;
    pys.push_back(make_pair(p, y));
    mp[p].push_back(y);
  }

  for (auto &e : mp) {
    sort(e.begin(), e.end());
  }

  for (auto &p : pys) {
    int pi = p.first;
    vector<int> &v = mp[pi];
    auto iter = lower_bound(v.begin(), v.end(), p.second);
    int x = iter - v.begin() + 1;

    cout << setw(6) << setfill('0') << pi;
    cout << setw(6) << setfill('0') << x;
    cout << "\n";
  }

  return 0;
}