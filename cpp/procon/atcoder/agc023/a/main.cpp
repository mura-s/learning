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

ll N;
vector<ll> A;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  A.resize(N);
  for (ll i = 0; i < N; i++) {
    cin >> A[i];
  }

  vector<ll> cum_A(N + 1, 0);
  for (int i = 1; i <= N; i++) {
    cum_A[i] = cum_A[i - 1] + A[i - 1];
  }
  sort(cum_A.begin(), cum_A.end());

  ll ans = 0;
  ll i = 1;
  while (i <= N) {
    ll l = 0;
    while (i <= N && cum_A[i - 1] == cum_A[i]) {
      l++;
      i++;
    }
    ans += l * (l + 1) / 2;
    i++;
  }

  cout << ans << endl;
  return 0;
}