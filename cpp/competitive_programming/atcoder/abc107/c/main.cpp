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
  vector<int> xs;
  for (int i = 0; i < N; ++i) {
    int xi;
    cin >> xi;
    xs.push_back(xi);
  }

  int ans = INT_MAX;
  for (int i = 0; i < N - K + 1; ++i) {
    int min_val = xs[i];
    int max_val = xs[i + K - 1];
    if (min_val < 0 && max_val < 0) {
      ans = min(ans, abs(min_val));
    } else if (min_val > 0 && max_val > 0) {
      ans = min(ans, max_val);
    } else {
      if (abs(min_val) < max_val) {
        ans = min(ans, 2 * abs(min_val) + max_val);
      } else {
        ans = min(ans, abs(min_val) + 2 * max_val);
      }
    }
  }

  cout << ans << endl;
  return 0;
}