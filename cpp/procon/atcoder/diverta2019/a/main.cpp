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

int N, K;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> K;

  int ans = N - K + 1;
  cout << ans << endl;
  return 0;
}