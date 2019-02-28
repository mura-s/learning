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

int N, T;
vector<int> c, t;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> T;
  c.resize(N);
  t.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> c[i] >> t[i];
  }

  int ans = INT_MAX;
  for (int i = 0; i < N; i++) {
    if (t[i] <= T) {
      ans = min(ans, c[i]);
    }
  }

  if (ans != INT_MAX) {
    cout << ans << endl;
  } else {
    cout << "TLE" << endl;
  }
  return 0;
}