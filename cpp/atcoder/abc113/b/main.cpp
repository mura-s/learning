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
  int N, T, A;
  cin >> N >> T >> A;
  vector<int> hs(N + 1);
  for (int i = 1; i <= N; i++) {
    cin >> hs[i];
  }

  int ans = 0;
  double diff = 100000000.0;
  for (int i = 1; i <= N; i++) {
    double temp = (double)T - hs[i] * 0.006;
    double diff_temp = abs(A - temp);
    if (diff_temp < diff) {
      ans = i;
      diff = diff_temp;
    }
  }

  cout << ans << endl;
  return 0;
}