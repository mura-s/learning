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

int gcd(int a, int b) {
  if (a < b) {
    return gcd(b, a);
  }

  while (a % b != 0) {
    int tmp = b;
    b = a % b;
    a = tmp;
  }
  return b;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<int> as;
  for (int i = 0; i < N; ++i) {
    int ai;
    cin >> ai;
    as.push_back(ai);
  }

  int ans = *min_element(as.begin(), as.end());
  for (int i = 0; i < N; ++i) {
    ans = gcd(ans, as[i]);
  }

  cout << ans << endl;
  return 0;
}