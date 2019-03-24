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
// const int INF = 2000000000;
// const ll MOD = 1000000007;

const int MAX_N = 100001;
int dp[MAX_N];

int N;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  for (int i = 0; i <= N; i++) {
    dp[i] = i;
  }

  for (int c = 6; c <= N; c *= 6) {
    for (int i = 0; i <= N; i++) {
      if (c <= i) {
        dp[i] = min(dp[i], dp[i - c] + 1);
      }
    }
  }
  for (int c = 9; c <= N; c *= 9) {
    for (int i = 0; i <= N; i++) {
      if (c <= i) {
        dp[i] = min(dp[i], dp[i - c] + 1);
      }
    }
  }

  cout << dp[N] << endl;
  return 0;
}