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

int main() {
  ll a = 10;
  ll b = 2;

  cout << gcd(a, b) << endl;
  cout << lcm(a, b) << endl;
  return 0;
}