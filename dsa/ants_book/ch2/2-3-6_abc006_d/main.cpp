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
const int INF = pow(10, 9);

int N;
vector<int> cs;
int dp[30001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  cs.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> cs[i];
  }
  fill(dp, dp + 30001, INF);

  // 最長部分列を高速に求める
  // https://www.slideshare.net/chokudai/abc006
  for (int i = 0; i < N; i++) {
    *lower_bound(dp, dp + 30001, cs[i]) = cs[i];
  }

  cout << N - (lower_bound(dp, dp + 30001, INF) - dp) << endl;
  return 0;
}