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

int N, W;
vector<int> v_vec, w_vec;
int dp[101][10001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> W;
  v_vec.resize(N);
  w_vec.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> v_vec[i] >> w_vec[i];
  }
  fill(dp[0], dp[101], 0);

  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= W; j++) {
      if (j - w_vec[i] >= 0) {
        dp[i + 1][j] = max(dp[i][j], dp[i + 1][j - w_vec[i]] + v_vec[i]);
      } else {
        dp[i + 1][j] = dp[i][j];
      }
    }
  }

  cout << dp[N][W] << endl;
  return 0;
}