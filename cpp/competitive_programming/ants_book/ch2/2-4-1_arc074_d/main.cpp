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

int N;
vector<long> a;
long a1_dp[100001];
long a2_dp[100001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  a.resize(3 * N);
  for (int i = 0; i < 3 * N; i++) {
    cin >> a[i];
  }

  // a1
  long a1_sum = 0;
  priority_queue<long, vector<long>, greater<long>> a1_pg;
  for (int i = 0; i < N; i++) {
    a1_sum += a[i];
    a1_pg.push(a[i]);
  }

  a1_dp[0] = a1_sum;
  for (int i = N; i < 2 * N; i++) {
    a1_pg.push(a[i]);
    long tmp = a1_pg.top();
    a1_pg.pop();
    a1_sum += a[i] - tmp;
    a1_dp[i - N + 1] = a1_sum;
  }

  // a2
  long a2_sum = 0;
  priority_queue<long> a2_pg;
  for (int i = 2 * N; i < 3 * N; i++) {
    a2_sum += a[i];
    a2_pg.push(a[i]);
  }

  a2_dp[N] = a2_sum;
  for (int i = 2 * N - 1; i >= N; i--) {
    a2_pg.push(a[i]);
    long tmp = a2_pg.top();
    a2_pg.pop();
    a2_sum += a[i] - tmp;
    a2_dp[i - N] = a2_sum;
  }

  // ans
  long ans = LONG_MIN;
  for (int i = 0; i <= N; i++) {
    ans = max(ans, a1_dp[i] - a2_dp[i]);
  }
  cout << ans << endl;
  return 0;
}