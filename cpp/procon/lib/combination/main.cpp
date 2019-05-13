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

// ref. https://www.kaoken.cg0.xyz/math_combination/

// 組み合わせ (combination) を求める
ll nCr(ll n, ll r) {
  if (r > n) {
    return 0;
  }
  if (r == 0) {
    return 1;
  }
  if (r * 2 > n) {
    r = n - r;
  }

  ll result = n;
  for (ll i = 2; i <= r; i++) {
    result *= (n - i + 1);
    result /= i;
  }
  return result;
}

// 重複組み合わせを求める
ll nHr(ll n, ll r) { return nCr(n + r - 1, r); }

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cout << nCr(10, 3) << endl;
  cout << nHr(7, 3) << endl;
  return 0;
}