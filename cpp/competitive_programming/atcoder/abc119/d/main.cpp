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
  int A, B, Q;
  cin >> A >> B >> Q;
  vector<long> ss(A), ts(B), xs(Q);
  for (int i = 0; i < A; i++) {
    cin >> ss[i];
  }
  for (int i = 0; i < B; i++) {
    cin >> ts[i];
  }
  for (int i = 0; i < Q; i++) {
    cin >> xs[i];
  }

  for (int i = 0; i < Q; i++) {
    long ans = LONG_MAX;
    long x = xs[i];

    auto s_high = lower_bound(ss.begin(), ss.end(), x);
    auto s_low = s_high - 1;
    auto t_high = lower_bound(ts.begin(), ts.end(), x);
    auto t_low = t_high - 1;

    if (s_high != ss.end() && t_high != ts.end()) {
      long tmp = *s_high - x;
      ans = min(ans, tmp + abs(*s_high - *t_high));
    }
    if (s_high != ss.end() && t_low != ts.begin() - 1) {
      long tmp = *s_high - x;
      ans = min(ans, tmp + abs(*s_high - *t_low));
    }
    if (s_low != ss.begin() - 1 && t_high != ts.end()) {
      long tmp = x - *s_low;
      ans = min(ans, tmp + abs(*s_low - *t_high));
    }
    if (s_low != ss.begin() - 1 && t_low != ts.begin() - 1) {
      long tmp = x - *s_low;
      ans = min(ans, tmp + abs(*s_low - *t_low));
    }

    if (t_high != ts.end() && s_high != ss.end()) {
      long tmp = *t_high - x;
      ans = min(ans, tmp + abs(*t_high - *s_high));
    }
    if (t_high != ts.end() && s_low != ss.begin() - 1) {
      long tmp = *t_high - x;
      ans = min(ans, tmp + abs(*t_high - *s_low));
    }
    if (t_low != ts.begin() - 1 && s_high != ss.end()) {
      long tmp = x - *t_low;
      ans = min(ans, tmp + abs(*t_low - *s_high));
    }
    if (t_low != ts.begin() - 1 && s_low != ss.begin() - 1) {
      long tmp = x - *t_low;
      ans = min(ans, tmp + abs(*t_low - *s_low));
    }

    cout << ans << endl;
  }

  return 0;
}