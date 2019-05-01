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

string S;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> S;

  if (S == "zyxwvutsrqponmlkjihgfedcba") {
    cout << -1 << endl;
    return 0;
  }

  string ans = "";
  if (S.size() == 26) {
    char c = 'a' - 1;
    int idx = 26;
    for (int i = 25; i >= 0; i--) {
      if (S[i] > c) {
        c = S[i];
      } else {
        idx = i;
        break;
      }
    }

    char last = 'z' + 1;
    for (int i = idx + 1; i < 26; i++) {
      if (S[i] > S[idx]) {
        last = min(last, S[i]);
      }
    }

    ans = S.substr(0, idx) + last;
  } else {
    vector<bool> b(26, false);
    for (int i = 0; i < S.size(); i++) {
      b[S[i] - 'a'] = true;
    }
    char next_c = '0';
    for (int i = 0; i < 26; i++) {
      if (!b[i]) {
        next_c = i + 'a';
        break;
      }
    }
    ans = S + next_c;
  }

  cout << ans << endl;
  return 0;
}