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

// 拡張gcd: ax + by = gcd(a, b) の整数解 (x, y) を求める.
// 返り値は gcd(a, b) の結果.
// ref. 蟻本
ll extgcd(ll a, ll b, ll &x, ll &y) {
  ll d = a;
  if (b != 0) {
    d = extgcd(b, a % b, y, x);
    y -= (a / b) * x;
  } else {
    x = 1;
    y = 0;
  }
  return d;
}

int main() {
  ll a = 10;
  ll b = 2;

  cout << gcd(a, b) << endl;
  cout << lcm(a, b) << endl;

  ll x = 0, y = 0;
  cout << extgcd(a, b, x, y) << endl;
  cout << x << " " << y << endl;

  return 0;
}