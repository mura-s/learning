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

int N, Q;
string S;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> Q;
  cin >> S;
  S = "x" + S;
  vector<int> c_sum(N + 1, 0);
  for (int i = 1; i <= N; i++) {
    if (S[i - 1] == 'A' && S[i] == 'C') {
      c_sum[i] = c_sum[i - 1] + 1;
    } else {
      c_sum[i] = c_sum[i - 1];
    }
  }

  for (int i = 0; i < Q; i++) {
    int l, r;
    cin >> l >> r;
    cout << c_sum[r] - c_sum[l] << endl;
  }

  return 0;
}