#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
// const int INF = 2000000000;

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
  sort(a.begin(), a.end(), greater<int>());

  int ans_n = a[0], ans_r = 0;
  int half = ans_n / 2;
  int min_diff = INF;
  for (int i = 1; i < N; i++) {
    int r = a[i];
    if (r > half) {
      r = ans_n - r;
    }
    if (half - r < min_diff) {
      min_diff = half - r;
      ans_r = a[i];
    }
  }

  cout << ans_n << " " << ans_r << endl;
  return 0;
}