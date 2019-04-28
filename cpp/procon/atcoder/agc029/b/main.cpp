#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
typedef long long ll;
// const ll MOD = 1000000007;
// const int INF = 2000000000;

ll N;
vector<ll> A;
unordered_map<ll, ll> mp;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  A.resize(N);
  for (ll i = 0; i < N; i++) {
    cin >> A[i];
    mp[A[i]]++;
  }
  sort(A.begin(), A.end());

  ll ans = 0;
  for (ll i = N - 1; i >= 1; i--) {
    if (mp[A[i]] == 0) {
      continue;
    }
    mp[A[i]]--;

    ll t = 0;
    ll a_tmp = A[i];
    while (a_tmp >= 1) {
      t++;
      a_tmp /= 2;
    }
    ll target = pow(2LL, t) - A[i];
    if (mp[target] > 0) {
      ans++;
      mp[target]--;
    }
  }

  cout << ans << endl;
  return 0;
}