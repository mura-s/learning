#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
const int INF = 2000000000;
// const ll MOD = 1000000007;

int N;
string S;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> S;

  vector<int> b_sum(N + 1, 0);
  vector<int> w_sum(N + 1, 0);
  for (int i = 1; i <= N; i++) {
    if (S[i - 1] == '#') {
      b_sum[i] = b_sum[i - 1] + 1;
      w_sum[i] = w_sum[i - 1];
    } else {
      b_sum[i] = b_sum[i - 1];
      w_sum[i] = w_sum[i - 1] + 1;
    }
  }

  int ans = INF;
  for (int i = 0; i <= N; i++) {
    int sum = (b_sum[i] - b_sum[0]) + (w_sum[N] - w_sum[i]);
    ans = min(ans, sum);
  }

  cout << ans << endl;
  return 0;
}