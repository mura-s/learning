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
// const long MOD = 1000000007;

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

int N;
vector<ll> T;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  T.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> T[i];
  }

  ll ans = T[0];
  for (int i = 1; i < N; i++) {
    ans = lcm(ans, T[i]);
  }

  cout << ans << endl;
  return 0;
}