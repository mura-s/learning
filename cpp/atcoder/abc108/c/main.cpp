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
  int N, K;
  cin >> N >> K;

  long ans = 0;
  if (K % 2 == 0) {
    long mod_0 = 0;
    long mod_half = 0;
    for (int i = 1; i <= N; ++i) {
      if (i % K == 0) {
        ++mod_0;
      }
      if (i % K == K / 2) {
        ++mod_half;
      }
    }
    ans += pow(mod_0, 3);
    ans += pow(mod_half, 3);
  } else {
    long mod_0 = 0;
    for (int i = 1; i <= N; ++i) {
      if (i % K == 0) {
        ++mod_0;
      }
    }
    ans += pow(mod_0, 3);
  }

  cout << ans << endl;
  return 0;
}