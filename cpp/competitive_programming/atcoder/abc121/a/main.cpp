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

int H, W;
int h, w;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> H >> W;
  cin >> h >> w;

  int ans = 0;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (i >= h && j >= w) {
        ans++;
      }
    }
  }

  cout << ans << endl;
  return 0;
}