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
  vector<long> xs(N, 0), ys(N, 0), zs(N, 0);
  for (int i = 0; i < N; ++i) {
    cin >> xs[i] >> ys[i] >> zs[i];
  }

  long ans = 0;
  for (int b = 0; b < (1 << 3); ++b) {
    vector<long> sums;
    for (int i = 0; i < N; ++i) {
      long tmp = 0;

      if ((b & 1) > 0) {
        tmp += xs[i];
      } else {
        tmp -= xs[i];
      }

      if ((b & (1 << 1)) > 0) {
        tmp += ys[i];
      } else {
        tmp -= ys[i];
      }

      if ((b & (1 << 2)) > 0) {
        tmp += zs[i];
      } else {
        tmp -= zs[i];
      }

      sums.push_back(tmp);
    }

    sort(sums.begin(), sums.end(), greater<long>());
    long tmp_ans = 0;
    for (int i = 0; i < M; ++i) {
      tmp_ans += sums[i];
    }

    ans = max(ans, tmp_ans);
  }

  cout << ans << endl;
  return 0;
}