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

int coins[6] = {500, 100, 50, 10, 5, 1};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, M;
  cin >> N;
  M = 1000 - N;

  int ans = 0;
  for (int i = 0; i < 6; i++) {
    int t = M / coins[i];
    ans += t;
    M -= coins[i] * t;
  }

  cout << ans << endl;
  return 0;
}