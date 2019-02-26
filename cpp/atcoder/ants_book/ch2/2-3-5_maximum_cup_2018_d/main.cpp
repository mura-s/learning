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

int N, M, L, X;
vector<int> as;
int dp[10001][1000];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M >> L >> X;
  as.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> as[i];
  }
  fill(dp[0], dp[10001], INF);
  dp[0][0] = 1;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (dp[i][j] != INF) {
        dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
        dp[i + 1][(j + as[i]) % M] =
            min(dp[i + 1][(j + as[i]) % M], dp[i][j] + (j + as[i]) / M);
      }
    }
  }

  if (dp[N][L] <= X) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}