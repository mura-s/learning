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

const ll MAX_L = 1000001;
const ll MAX_SQRT_B = 1000001;

bool is_prime[MAX_L];
bool is_prime_small[MAX_SQRT_B];

void segment_sieve(ll a, ll b) {
  for (ll i = 0; i * i < b; i++) {
    is_prime_small[i] = true;
  }
  for (ll i = 0; i < b - a; i++) {
    is_prime[i] = true;
  }

  for (ll i = 2; i * i < b; i++) {
    if (is_prime_small[i]) {
      for (ll j = 2 * i; j * j < b; j += i) {
        is_prime_small[j] = false;
      }

      ll tmp = (a + i - 1) / i;
      for (ll j = max(2ll, tmp) * i; j < b; j += i) {
        is_prime[j - a] = false;
      }
    }
  }
}

ll a, b;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> a >> b;
  segment_sieve(a, b);

  ll ans = 0;
  for (ll i = 0; i < b - a; i++) {
    if (is_prime[i]) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}