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

vector<ll> divisor(ll n) {
  vector<ll> res;
  for (ll i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      res.push_back(i);
      if (i != n / i) {
        res.push_back(n / i);
      }
    }
  }
  return res;
}

ll N;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  vector<ll> ds = divisor(N);

  ll ans = 0;
  for (auto &e : ds) {
    if (e == 1 || e == 2) {
      continue;
    }

    ll d = N / e; // 商 かつ あまり
    if ((N - d) % d == 0) {
      ll m = (N - d) / d;
      if ((N / m) == (N % m)) {
        ans += m;
      }
    }
  }

  cout << ans << endl;
  return 0;
}