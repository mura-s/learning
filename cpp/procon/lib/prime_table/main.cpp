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

const int MAX_N = 10000;

int prime[MAX_N];
bool is_prime[MAX_N + 1];

// prime table
int eratosthenes(int n) {
  int p = 0;
  for (int i = 0; i <= n; i++) {
    is_prime[i] = true;
  }
  is_prime[0] = false, is_prime[1] = false;

  for (int i = 2; i <= n; i++) {
    if (!is_prime[i]) {
      continue;
    }
    prime[p++] = i;
    for (int j = 2 * i; j <= n; j += i) {
      is_prime[j] = false;
    }
  }

  return p;
}

int N;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  N = 100;

  int p = eratosthenes(N);
  for (int i = 0; i < p; i++) {
    cout << prime[i] << endl;
  }
  return 0;
}