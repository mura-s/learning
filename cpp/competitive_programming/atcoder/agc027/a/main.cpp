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
  int N, x;
  cin >> N >> x;
  vector<int> a;
  for (int i = 0; i < N; ++i) {
    int ai;
    cin >> ai;
    a.push_back(ai);
  }
  sort(a.begin(), a.end());

  int ans = 0;
  for (int i = 0; i < N; ++i) {
    if (x >= a[i]) {
      ++ans;
      x -= a[i];
    }
  }

  if (ans == N && x != 0) {
    --ans;
  }

  cout << ans << endl;
  return 0;
}