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
// const int INF = 2000000000;
// const ll MOD = 1000000007;

int N, K;
string S;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> K;
  cin >> S;

  int ans = 0;
  int l = 0, r = 0;

  // 最初のrの位置まで進める
  int num_zero = 0;
  while (r < N) {
    while (r < N && S[r] == '1') {
      r++;
    }
    if (++num_zero > K) {
      break;
    }
    while (r < N && S[r] == '0') {
      r++;
    }
  }
  ans = max(ans, r - l);

  // l, rを動かしながら、最大のansを求める
  while (r < N) {
    // lを進める
    while (l < N && S[l] == '1') {
      l++;
    }
    while (l < N && S[l] == '0') {
      l++;
    }

    // rを進める
    while (r < N && S[r] == '0') {
      r++;
    }
    while (r < N && S[r] == '1') {
      r++;
    }
    ans = max(ans, r - l);
  }

  cout << ans << endl;
  return 0;
}