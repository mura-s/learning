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

int R, G, B, N;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> R >> G >> B >> N;

  int ans = 0;

  for (int i = 0; i <= N; i++) {
    for (int j = 0; j <= N; j++) {
      int sum = R * i + G * j;
      if (sum < N && (N - sum) % B == 0) {
        ans++;
      } else if (sum == N) {
        ans++;
      }
    }
  }

  cout << ans << endl;
  return 0;
}