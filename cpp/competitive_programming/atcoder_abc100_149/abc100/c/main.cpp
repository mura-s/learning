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
  int N;
  cin >> N;
  int ans = 0;
  for (int i = 0; i < N; ++i) {
    int ai;
    cin >> ai;
    while (ai % 2 == 0) {
      ++ans;
      ai /= 2;
    }
  }

  cout << ans << endl;
  return 0;
}