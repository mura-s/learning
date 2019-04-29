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

ll gcd(ll a, ll b) {
  if (a < b) {
    return gcd(b, a);
  }

  while (a % b != 0) {
    ll tmp = b;
    b = a % b;
    a = tmp;
  }
  return b;
}

ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

ll N, M;
string S, T;
ll L;

ll solve() {
  map<ll, char> mp;
  for (ll i = 0; i < N; i++) {
    ll idx = i * (L / N) + 1;
    mp[idx] = S[i];
  }

  for (ll i = 0; i < M; i++) {
    ll idx = i * (L / M) + 1;
    if (mp.find(idx) != mp.end() && mp[idx] != T[i]) {
      return -1;
    }
  }

  return L;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M;
  cin >> S >> T;
  L = lcm(N, M);

  cout << solve() << endl;
  return 0;
}