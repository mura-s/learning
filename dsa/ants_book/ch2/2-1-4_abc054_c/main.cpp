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
  int N, M;
  cin >> N >> M;
  bool ab[N + 1][N + 1];
  fill(ab[0], ab[N + 1], false);
  for (int i = 0; i < M; ++i) {
    int ai, bi;
    cin >> ai >> bi;
    ab[ai][bi] = true;
  }

  vector<int> nodes(N - 1, 0);
  for (int i = 2; i <= N; ++i) {
    nodes[i - 2] = i;
  }

  int ans = 0;
  do {
    if (!ab[1][nodes[0]]) {
      continue;
    }

    bool flag = true;
    for (int i = 0; i < N - 2; ++i) {
      int a = nodes[i], b = nodes[i + 1];
      if (a > b) {
        swap(a, b);
      }
      if (!ab[a][b]) {
        flag = false;
        break;
      }
    }

    if (flag) {
      ++ans;
    }
  } while (next_permutation(nodes.begin(), nodes.end()));

  cout << ans << endl;
  return 0;
}