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
const ll INF = LONG_MAX;
// const ll MOD = 1000000007;

ll N;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  ll m = INF;
  for (int i = 0; i < 5; i++) {
    ll tmp;
    cin >> tmp;
    if (tmp < m) {
      m = tmp;
    }
  }

  ll ans = 0;
  if (N % m == 0) {
    ans = N / m;
  } else {
    ans = (N / m) + 1;
  }

  cout << ans + 4 << endl;
  return 0;
}