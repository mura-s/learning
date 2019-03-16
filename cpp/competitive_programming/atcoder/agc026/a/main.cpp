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
typedef long long ll;

int N;
vector<int> a;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  a.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }

  int ans = 0;
  for (int i = 1; i < N; i++) {
    if (a[i] == a[i - 1]) {
      ans++;
      a[i] = 0;
    }
  }

  cout << ans << endl;
  return 0;
}