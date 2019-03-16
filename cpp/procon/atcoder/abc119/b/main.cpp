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
  int N;
  cin >> N;
  vector<double> xs(N);
  vector<string> us(N);
  for (int i = 0; i < N; i++) {
    cin >> xs[i] >> us[i];
  }

  double ans = 0.0;
  for (int i = 0; i < N; i++) {
    if (us[i] == "JPY") {
      ans += xs[i];
    } else if (us[i] == "BTC") {
      ans += (xs[i] * 380000.0);
    }
  }

  cout << ans << endl;
  return 0;
}