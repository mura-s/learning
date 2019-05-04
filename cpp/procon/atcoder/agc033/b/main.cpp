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

  int max_l = sc;
  int max_r = sc;
  int max_u = sr;
  int max_d = sr;

  bool flag = true;
  for (int i = 0; i < N; i++) {
    // takahashi
    if (S[i] == 'L') {
      max_l--;
    }
    if (S[i] == 'R') {
      max_r++;
    }
    if (S[i] == 'U') {
      max_u--;
    }
    if (S[i] == 'D') {
      max_d++;
    }

    // result
    if (max_l < 0 || max_r >= W || max_u < 0 || max_d >= H) {
      flag = false;
      break;
    }

    // aoki
    if (T[i] == 'L' && max_r - 1 >= 0) {
      max_r--;
    }
    if (T[i] == 'R' && max_l + 1 < W) {
      max_l++;
    }
    if (T[i] == 'U' && max_d - 1 >= 0) {
      max_d--;
    }
    if (T[i] == 'D' && max_u + 1 < H) {
      max_u++;
    }
  }

  if (flag) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}