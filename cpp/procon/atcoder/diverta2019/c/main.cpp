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

int N;
vector<string> S;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  S.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> S[i];
  }

  int ans = 0;
  int ab_num = 0;
  int a_num = 0;
  int b_num = 0;

  for (int i = 0; i < N; i++) {
    string s = S[i];
    int last = s.size() - 1;
    if (s[0] == 'B' && s[last] == 'A') {
      ab_num++;
    } else if (s[0] == 'B') {
      b_num++;
    } else if (s[last] == 'A') {
      a_num++;
    }

    for (int j = 1; j <= last; j++) {
      if (s[j - 1] == 'A' && s[j] == 'B') {
        ans++;
      }
    }
  }

  if (ab_num > 0) {
    ans += (ab_num - 1);
  }
  if (ab_num > 0 && (a_num > 0 || b_num > 0)) {
    a_num++;
    b_num++;
  }

  ans += min(a_num, b_num);
  cout << ans << endl;
  return 0;
}