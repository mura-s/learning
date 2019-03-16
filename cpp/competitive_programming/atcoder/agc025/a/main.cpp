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

int N;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;

  int ans = INT_MAX;
  for (int i = 1; i < N; i++) {
    int a = i, b = N - i;
    int m = 0;
    while (a > 0) {
      m += a % 10;
      a /= 10;
    }
    while (b > 0) {
      m += b % 10;
      b /= 10;
    }
    ans = min(ans, m);
  }

  cout << ans << endl;
  return 0;
}