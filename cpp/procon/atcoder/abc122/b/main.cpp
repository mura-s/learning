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
// const int INF = 2000000000;
// const ll MOD = 1000000007;

string S;

bool f(char c) {
  if (c == 'A' || c == 'C' || c == 'G' || c == 'T') {
    return true;
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> S;

  int ans = 0;
  int last = 0;
  for (int i = 0; i < S.size(); i++) {
    if (f(S[i])) {
      last++;
    } else {
      ans = max(ans, last);
      last = 0;
    }
  }
  ans = max(ans, last);

  cout << ans << endl;
  return 0;
}