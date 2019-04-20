#include <algorithm>
#include <climits>
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
// const ll MOD = 1000000007;

int N, H;
int max_a;
vector<int> a, b;
vector<int> use_b;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> H;
  a.resize(N);
  b.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i] >> b[i];
    max_a = max(max_a, a[i]);
  }

  for (int i = 0; i < N; i++) {
    if (max_a < b[i]) {
      use_b.push_back(b[i]);
    }
  }
  sort(use_b.begin(), use_b.end(), greater<int>());

  int cnt = 0;
  for (int i = 0; i < use_b.size(); i++) {
    H -= use_b[i];
    cnt++;
    if (H <= 0) {
      cout << cnt << endl;
      return 0;
    }
  }

  if (H % max_a == 0) {
    cnt += (H / max_a);
  } else {
    cnt += (H / max_a) + 1;
  }

  cout << cnt << endl;
  return 0;
}