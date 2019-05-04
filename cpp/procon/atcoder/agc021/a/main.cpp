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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;

  ll ans1 = 0;
  ll ans2 = 0; // sum of all digit

  ll top = 0;
  ll num_digit = 0;
  while (N != 0) {
    top = N % 10;
    num_digit++;
    N /= 10;

    ans2 += top;
  }
  ans1 = (top - 1) + 9 * (num_digit - 1);

  cout << max(ans1, ans2) << endl;
  return 0;
}