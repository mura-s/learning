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

  int X, K;
  cin >> X >> K;

  for (int i = 0; i < K; i++) {
    X /= 10;
  }

  int ans = X * pow(10, K) + 1 * pow(10, K);
  cout << ans << "\n";
  return 0;
}