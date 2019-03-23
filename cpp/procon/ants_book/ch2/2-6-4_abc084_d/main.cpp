#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;
typedef long long ll;
// const int INF = 2000000000;
// const ll MOD = 1000000007;

const int MAX_N = 100000;

unordered_set<int> prime;
bool is_prime[MAX_N + 1];

// prime table
void eratosthenes(int n) {
  for (int i = 0; i <= n; i++) {
    is_prime[i] = true;
  }
  is_prime[0] = false, is_prime[1] = false;

  for (int i = 2; i <= n; i++) {
    if (!is_prime[i]) {
      continue;
    }
    prime.insert(i);
    for (int j = 2 * i; j <= n; j += i) {
      is_prime[j] = false;
    }
  }
}

int Q;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  eratosthenes(MAX_N);
  vector<int> c_sum(MAX_N + 1, 0);
  for (int i = 1; i <= MAX_N; i++) {
    if (prime.find(i) == prime.end() ||
        prime.find((i + 1) / 2) == prime.end()) {
      c_sum[i] = c_sum[i - 1];
    } else {
      c_sum[i] = c_sum[i - 1] + 1;
    }
  }

  cin >> Q;
  for (int i = 0; i < Q; i++) {
    int l, r;
    cin >> l >> r;
    cout << c_sum[r] - c_sum[l - 1] << endl;
  }
  return 0;
}