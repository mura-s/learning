#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
typedef long long ll;
// const ll MOD = 1000000007;
// const int INF = 2000000000;
const int MAX_SIZE = 2 * 100000;

int N, C;
unordered_map<int, vector<bool>> mp;
vector<int> num_chans(MAX_SIZE, 0);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> C;
  for (int i = 0; i < N; i++) {
    int s, t, c;
    cin >> s >> t >> c;
    if (mp[c].empty()) {
      mp[c].resize(MAX_SIZE, 0);
    }
    for (int j = 2 * s - 1; j <= 2 * t - 1; j++) {
      mp[c][j] = true;
    }
  }

  for (auto &e : mp) {
    for (int i = 0; i < MAX_SIZE; i++) {
      if (e.second[i]) {
        num_chans[i]++;
      }
    }
  }

  sort(num_chans.begin(), num_chans.end(), greater<int>());
  int ans = num_chans[0];
  cout << ans << endl;
  return 0;
}