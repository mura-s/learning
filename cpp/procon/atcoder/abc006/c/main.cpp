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

int N, M;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M;

  // 4: a
  // 3: b
  // 2: c

  for (int b = 0; b < M; b++) {
    int sum = M - 2 * N - b;
    if (sum >= 0 && sum % 2 == 0) {
      int a = sum / 2;
      int c = N - a - b;

      if (c >= 0) {
        cout << c << " " << b << " " << a << endl;
        return 0;
      }
    }
  }

  cout << "-1 -1 -1" << endl;
  return 0;
}