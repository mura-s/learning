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
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N, K;
  cin >> N >> K;
  vector<int> as;
  for (int i = 0; i < N; ++i) {
    int ai;
    cin >> ai;
    as.push_back(ai);
  }
  int one_idx = distance(as.begin(), min_element(as.begin(), as.end()));
  int lower_cnt = one_idx;
  int upper_cnt = N - one_idx - 1;
  int K_dash = K - 1;

  int ans = 0;
  ans += lower_cnt / K_dash;
  int r = lower_cnt % K_dash;
  if (r != 0) {
    ++ans;
    upper_cnt -= (K_dash - r);
    upper_cnt = max(0, upper_cnt);
  }

  ans += upper_cnt / K_dash;
  if (upper_cnt % K_dash != 0) {
    ++ans;
  }

  cout << ans << endl;
  return 0;
}