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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, M, Q;
  cin >> N >> M >> Q;
  vector<vector<int>> seg(N + 1, vector<int>());
  for (int i = 1; i <= M; ++i) {
    int l, r;
    cin >> l >> r;
    seg[l].push_back(r);
  }

  for (auto &e : seg) {
    sort(e.begin(), e.end());
  }

  vector<pair<int, int>> pq;
  for (int i = 1; i <= Q; ++i) {
    int p, q;
    cin >> p >> q;
    pq.push_back(make_pair(p, q));
  }

  for (auto &e : pq) {
    int p = e.first;
    int q = e.second;
    int ans = 0;
    for (int i = p; i <= q; ++i) {
      ans += upper_bound(seg[i].begin(), seg[i].end(), q) -
             lower_bound(seg[i].begin(), seg[i].end(), p);
    }
    cout << ans << '\n';
  }
  return 0;
}
