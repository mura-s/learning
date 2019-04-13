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

int N;
vector<int> H;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  H.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> H[i];
  }

  int ans = 0;
  int m = 0;
  for (int i = 0; i < N; i++) {
    if (H[i] >= m) {
      ans++;
      m = H[i];
    }
  }

  cout << ans << endl;
  return 0;
}