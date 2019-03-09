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

const long mod = 1000000007;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int H, W, K;
  cin >> H >> W >> K;
  long dp[H + 1][W];
  fill(dp[0], dp[H + 1], 0);
  dp[0][0] = 1;

  for (int h = 0; h < H; ++h) {
    for (int b = 0; b < (1 << (W - 1)); ++b) { // 立っているbit = 横棒
      // 隣り合っているケース
      bool ok = true;
      for (int i = 0; i < W - 2; ++i) {
        if ((b >> i) % 4 == 3) {
          ok = false;
          break;
        }
      }
      if (!ok) {
        continue;
      }

      // 移動先
      int ws[W];
      for (int i = 0; i < W; ++i) {
        ws[i] = i;
      }
      for (int i = 0; i < W - 1; ++i) {
        if ((b >> i) % 2 == 1) {
          swap(ws[i], ws[i + 1]);
        }
      }

      // dpを計算
      for (int i = 0; i < W; ++i) {
        dp[h + 1][ws[i]] += dp[h][i];
        dp[h + 1][ws[i]] %= mod;
      }
    }
  }

  cout << dp[H][K - 1] << "\n";
  return 0;
}