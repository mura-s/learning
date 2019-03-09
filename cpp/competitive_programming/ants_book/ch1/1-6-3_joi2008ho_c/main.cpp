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
  int N, M;
  cin >> N >> M;
  vector<int> ps(N + 1, 0);
  ps[0] = 0;
  for (int i = 1; i <= N; ++i) {
    cin >> ps[i];
  }

  vector<int> pps((N + 1) * (N + 2) / 2, 0);
  int cnt = 0;
  for (int i = 0; i <= N; ++i) {
    for (int j = i; j <= N; ++j) {
      pps[cnt] = ps[i] + ps[j];
      ++cnt;
    }
  }
  sort(pps.begin(), pps.end());

  int ans = 0;
  for (int i = 0; i <= N; ++i) {
    for (int j = i; j <= N; ++j) {
      int tmp = M - ps[i] - ps[j];
      auto ub = upper_bound(pps.begin(), pps.end(), tmp);
      if (ub != pps.begin()) {
        ans = max(ans, ps[i] + ps[j] + *(ub - 1));
      }
    }
  }

  cout << ans << endl;
  return 0;
}