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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N, M;
  cin >> N >> M;
  vector<int> cnt_vec(M + 1, 0);
  for (int i = 1; i <= N; ++i) {
    int ki;
    cin >> ki;
    for (int j = 1; j <= ki; ++j) {
      int ai;
      cin >> ai;
      ++cnt_vec[ai];
    }
  }

  int ans = 0;
  for (int i = 1; i <= M; ++i) {
    if (cnt_vec[i] == N) {
      ++ans;
    }
  }
  cout << ans << endl;
  return 0;
}