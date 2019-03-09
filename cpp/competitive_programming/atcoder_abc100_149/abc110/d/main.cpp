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
vector<pair<long, long>> prime_factorize(long n) {
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

const int MOD = 1000000007;
const int MAX = 200001;
long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void comb_init() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < MAX; i++) {
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
}

// 二項係数計算 (combination. nCkを求める.)
long comb(int n, int k) {
  if (n < k) {
    return 0;
  }
  if (n < 0 || k < 0) {
    return 0;
  }
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  comb_init();

  long N, M;
  cin >> N >> M;
  vector<pair<long, long>> primes = prime_factorize(M);

  long res = 1;
  for (auto &p : primes) {
    long num = p.second;
    res = (res * comb(num + N - 1, N - 1)) % MOD;
  }

  cout << res << endl;
  return 0;
}