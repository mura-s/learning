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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int D, G;
  cin >> D >> G;
  int ps[D + 1];
  int cs[D + 1];
  vector<int> perm_vec;
  for (int i = 1; i <= D; ++i) {
    int pi, ci;
    cin >> pi >> ci;
    ps[i] = pi;
    cs[i] = ci;
    perm_vec.push_back(i);
  }
  int ans = INT_MAX;

  do {
    int G2 = G;
    int cnt = 0;
    for (int k = 0; k < D; ++k) {
      int i = perm_vec[k];
      if (G2 > ps[i] * 100 * i + cs[i]) {
        G2 -= ps[i] * 100 * i + cs[i];
        cnt += ps[i];
        continue;
      }

      for (int j = 0; j < ps[i]; ++j) {
        if (j == ps[i] - 1) {
          G2 -= cs[i];
        }
        G2 -= 100 * i;
        ++cnt;
        if (G2 <= 0) {
          goto BREAK;
        }
      }
    }

  BREAK:
    ans = min(ans, cnt);
  } while (next_permutation(perm_vec.begin(), perm_vec.end()));

  cout << ans << endl;
  return 0;
}