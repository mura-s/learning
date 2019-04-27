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
// const ll MOD = 1000000007;
// const int INF = 2000000000;

int N;
vector<int> V, C;

int dfs(int idx) {
  if (idx == N) {
    return 0;
  }

  int m1 = dfs(idx + 1) + V[idx] - C[idx];
  int m2 = dfs(idx + 1);
  return max(m1, m2);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  V.resize(N);
  C.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> V[i];
  }
  for (int i = 0; i < N; i++) {
    cin >> C[i];
  }

  int ans = dfs(0);
  cout << ans << endl;
  return 0;
}