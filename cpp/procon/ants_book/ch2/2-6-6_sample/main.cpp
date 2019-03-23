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

ll MOD, n;

// 繰り返し二乗法 (O(logn))
ll power(ll x, ll n) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) {
      res = res * x % MOD;
    }
    x = x * x % MOD;
    n >>= 1;
  }
  return res;
}

// 蟻本の例題.
// だだし入力nは素数でないとする.
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  MOD = n;

  for (int x = 2; x < n; x++) {
    if (power(x, n) % MOD != x % MOD) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}