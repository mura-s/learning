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

double calc(int x1, int y1, int x2, int y2) {
  double dx1 = (double)x1;
  double dy1 = (double)y1;
  double dx2 = (double)x2;
  double dy2 = (double)y2;
  return sqrt(pow(dx2 - dx1, 2) + pow(dy2 - dy1, 2));
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  vector<int> xs(N, 0), ys(N, 0);
  for (int i = 0; i < N; ++i) {
    cin >> xs[i] >> ys[i];
  }

  double ans = 0.0;
  for (int i = 0; i < N; ++i) {
    for (int j = i + 1; j < N; ++j) {
      ans = max(ans, calc(xs[i], ys[i], xs[j], ys[j]));
    }
  }

  cout << fixed << setprecision(6) << ans << endl;
  return 0;
}