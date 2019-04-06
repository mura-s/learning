#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
// const int INF = 2000000000;
// const ll MOD = 1000000007;

const int MAX_N = 55555;

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
  cin >> N;
  int p = eratosthenes(MAX_N);

  int cnt = 0;
  for (int i = 0; i < p; i++) {
    if (prime[i] % 5 == 1) {
      cout << prime[i];
      cnt++;

      if (cnt == N) {
        cout << endl;
        break;
      }
      cout << " ";
    }
  }

  return 0;
}