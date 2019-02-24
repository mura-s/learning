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

const int INF = pow(10, 9);

int N;
int A, B, C;
vector<int> ls;

int dfs(int idx, int a, int b, int c) {
  if (idx == N) {
    if (a == 0 || b == 0 || c == 0) {
      return INF;
    }
    return abs(A - a) + abs(B - b) + abs(C - c) - 30;
  }

  int v1 = dfs(idx + 1, a, b, c);
  int v2 = dfs(idx + 1, a + ls[idx], b, c) + 10;
  int v3 = dfs(idx + 1, a, b + ls[idx], c) + 10;
  int v4 = dfs(idx + 1, a, b, c + ls[idx]) + 10;

  return min(v1, min(v2, min(v3, v4)));
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> A >> B >> C;
  ls.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> ls[i];
  }

  cout << dfs(0, 0, 0, 0) << endl;
  return 0;
}