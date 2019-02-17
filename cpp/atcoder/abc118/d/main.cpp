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

void chmax(string &s1, string s2) {
  if (s1.size() < s2.size()) {
    s1 = s2;
    return;
  }

  if (s1.size() == s2.size() && s1 < s2) {
    s1 = s2;
    return;
  }

  return;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int matches[10] = {-1, 2, 5, 5, 4, 5, 6, 3, 7, 6};

  int N, M;
  cin >> N >> M;
  vector<int> as;
  for (int i = 0; i < M; ++i) {
    int ai;
    cin >> ai;
    as.push_back(ai);
  }

  string dp[10001];
  fill(dp, dp + 10001, "");
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < as.size(); ++j) {
      if (i == 0 || dp[i] != "") {
        int match = matches[as[j]];
        if (i + match <= N) {
          chmax(dp[i + match], dp[i] + to_string(as[j]));
        }
      }
    }
  }

  cout << dp[N] << endl;
}