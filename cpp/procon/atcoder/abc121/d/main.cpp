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

ll A, B;

ll f(ll x) {
  ll f_x = 0;

  if ((x + 1) % 2 == 0) {
    ll one_cnt = (x + 1) / 2;
    f_x = one_cnt % 2;
  } else {
    ll one_cnt = (x + 1) / 2;
    f_x = one_cnt % 2;
    f_x ^= x;
  }

  return f_x;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> A >> B;

  if (A == 0 && B == 0) {
    cout << 0 << endl;
    return 0;
  }
  if (A == 0) {
    cout << f(B) << endl;
    return 0;
  }

  A--;

  // F(0, A-1)
  ll f_a = f(A);

  // F(0, B)
  ll f_b = f(B);

  cout << (f_a ^ f_b) << endl;
  return 0;
}