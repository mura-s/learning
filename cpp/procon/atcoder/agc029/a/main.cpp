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

string S;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> S;

  ll ans = 0;
  ll num_w = 0;
  for (ll i = S.size() - 1; i >= 0; i--) {
    if (S[i] == 'W') {
      num_w++;
    } else {
      ans += num_w;
    }
  }

  cout << ans << endl;
  return 0;
}