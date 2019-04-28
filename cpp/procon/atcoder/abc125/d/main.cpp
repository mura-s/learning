#include <algorithm>
#include <climits>
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
// const ll MOD = 1000000007;
// const int INF = 2000000000;

ll N;
vector<ll> A;
vector<ll> abs_A;
bool has_zero = false;
int num_minus = 0;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  A.resize(N);
  abs_A.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    abs_A[i] = abs(A[i]);
    if (A[i] == 0) {
      has_zero = true;
    }
    if (A[i] < 0) {
      num_minus++;
    }
  }

  ll ans = 0;
  if (has_zero) {
    for (auto &e : abs_A) {
      ans += e;
    }
  } else {
    for (auto &e : abs_A) {
      ans += e;
    }
    if (num_minus % 2 != 0) {
      sort(abs_A.begin(), abs_A.end());
      ans -= (2 * abs_A[0]);
    }
  }

  cout << ans << endl;
  return 0;
}