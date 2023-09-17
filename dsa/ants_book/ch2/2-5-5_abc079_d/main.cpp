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
const int MAX_V = 10;

int d[MAX_V][MAX_V];
int V = MAX_V;

void warshall_floyd() {
  for (int k = 0; k < V; k++) {
    for (int i = 0; i < V; i++) {
      for (int j = 0; j < V; j++) {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
}

int H, W;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> H >> W;
  for (int i = 0; i < V; i++) {
    for (int j = 0; j < V; j++) {
      cin >> d[i][j];
    }
  }
  warshall_floyd();

  int ans = 0;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      int a;
      cin >> a;
      if (a == -1 || a == 1) {
        continue;
      }
      ans += d[a][1];
    }
  }
  cout << ans << endl;
  return 0;
}