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
  ios::sync_with_stdio(false);
  cin.tie(0);
  long N, M;
  cin >> N >> M;
  vector<long> sums(N + 1, 0);
  for (long i = 1; i <= N; ++i) {
    long a;
    cin >> a;
    sums[i] += sums[i - 1] + a;
  }

  map<long, long> rems;
  for (long i = 0; i <= N; ++i) {
    ++rems[sums[i] % M];
  }

  long ans = 0;
  for (auto &e : rems) {
    long n = e.second;
    ans += (n * (n - 1) / 2);
  }

  cout << ans << endl;
  return 0;
}