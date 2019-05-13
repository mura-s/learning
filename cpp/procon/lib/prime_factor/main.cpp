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

// 素因数分解
// 素数の値と個数のpairのvectorを返す
vector<pair<long, long>> prime_factor(long n) {
  vector<pair<long, long>> v;

  for (long p = 2; p * p <= n; ++p) {
    if (n % p != 0) {
      continue;
    }
    long num = 0;
    while (n % p == 0) {
      ++num;
      n /= p;
    }
    v.push_back(make_pair(p, num));
  }

  if (n != 1) {
    v.push_back(make_pair(n, 1));
  }

  return v;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  long M = 48;
  vector<pair<long, long>> primes = prime_factor(M);

  for (auto &e : primes) {
    cout << e.first << " " << e.second << endl;
  }
  return 0;
}