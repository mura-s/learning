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

int H, W, N;
int sr, sc;
string S, T;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> H >> W >> N;
  cin >> sr >> sc;
  sr--;
  sc--;
  cin >> S >> T;

  int l = 0;
  int r = W - 1;
  int u = 0;
  int d = H - 1;

  for (int i = N - 1; i >= 0; i--) {
    if (r < l || d < u) {
      break;
    }

    // T
    if (T[i] == 'L' && r + 1 <= W - 1) {
      r++;
    }
    if (T[i] == 'R' && l - 1 >= 0) {
      l--;
    }
    if (T[i] == 'U' && d + 1 <= H - 1) {
      d++;
    }
    if (T[i] == 'D' && u - 1 >= 0) {
      u--;
    }

    // S
    if (S[i] == 'L') {
      l++;
    }
    if (S[i] == 'R') {
      r--;
    }
    if (S[i] == 'U') {
      u++;
    }
    if (S[i] == 'D') {
      d--;
    }
  }

  if (l <= sc && sc <= r && u <= sr && sr <= d) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}