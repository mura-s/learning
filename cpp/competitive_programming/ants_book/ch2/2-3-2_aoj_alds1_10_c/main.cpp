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
typedef long long ll;

int dp[1001][1001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int q;
  cin >> q;
  vector<string> xs(q), ys(q);
  for (int i = 0; i < q; i++) {
    cin >> xs[i] >> ys[i];
  }

  for (int i = 0; i < q; i++) {
    fill(dp[0], dp[1001], 0);
    string x = xs[i], y = ys[i];
    for (int j = 0; j < x.size(); j++) {
      for (int k = 0; k < y.size(); k++) {
        if (x[j] == y[k]) {
          dp[j + 1][k + 1] = dp[j][k] + 1;
        } else {
          dp[j + 1][k + 1] = max(dp[j][k + 1], dp[j + 1][k]);
        }
      }
    }

    cout << dp[x.size()][y.size()] << endl;
    ;
  }
  return 0;
}