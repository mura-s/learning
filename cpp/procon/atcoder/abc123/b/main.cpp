#include <algorithm>
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
const int INF = 2000000000;
// const ll MOD = 1000000007;

vector<int> vec(5);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int min_d = INF;
  int min_idx = 0;
  for (int i = 0; i < 5; i++) {
    cin >> vec[i];
    int d = vec[i] % 10;
    if (d == 0) {
      continue;
    }
    if (d < min_d) {
      min_d = d;
      min_idx = i;
    }
  }

  int ans = 0;
  for (int i = 0; i < 5; i++) {
    if (vec[i] % 10 == 0) {
      ans += vec[i];
      continue;
    }
    if (i == min_idx) {
      ans += vec[i];
    } else {
      ans += vec[i] + (10 - (vec[i] % 10));
    }
  }

  cout << ans << endl;
  return 0;
}