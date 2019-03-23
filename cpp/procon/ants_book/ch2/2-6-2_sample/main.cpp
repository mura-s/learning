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

ll a, b;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> a >> b;
  ll x = 0, y = 0;
  ll gcd = extgcd(a, b, x, y);
  if (gcd == 1) {
    cout << x << " " << y << endl;
  } else {
    cout << -1 << endl;
  }
  return 0;
}