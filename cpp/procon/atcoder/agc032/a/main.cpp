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
// const int INF = 2000000000;
// const ll MOD = 1000000007;

int N;
vector<pair<int, bool>> b;
vector<int> ans;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  b.resize(N + 1);
  ans.resize(N + 1);
  for (int i = 1; i <= N; i++) {
    int bi;
    cin >> bi;
    b[i] = make_pair(bi, true);
  }

  int pos = N;
  for (int i = 1; i <= N; i++) {
    int unused_idx = 1;
    int r = 0;
    for (int j = 1; j <= N; j++) {
      if (b[j].second) {
        if (unused_idx == b[j].first) {
          r = j;
        }
        unused_idx++;
      }
    }

    if (r == 0) {
      break;
    }
    ans[pos] = b[r].first;
    b[r].second = false;
    pos--;
  }

  if (pos == 0) {
    for (int i = 1; i <= N; i++) {
      cout << ans[i] << endl;
    }
  } else {
    cout << -1 << endl;
  }
  return 0;
}