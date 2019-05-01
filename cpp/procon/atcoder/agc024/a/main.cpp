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

ll A, B, C, K;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> A >> B >> C >> K;

  ll ans = 0;
  if (K % 2 == 0) {
    ans = A - B;
  } else {
    ans = B - A;
  }

  cout << ans << endl;
  return 0;
}