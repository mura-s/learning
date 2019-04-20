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
const int INF = 2000000000;
// const ll MOD = 1000000007;

const int MAX_N = 100001;
struct edge {
  int to, cost;
};
vector<edge> g[MAX_N];
int d[MAX_N];
bool visit[MAX_N];

int N, M;

bool dfs(int v, int cost) {
  if (visit[v]) {
    return d[v] == cost;
  }
  visit[v] = true;
  d[v] = cost;

  for (int i = 0; i < g[v].size(); i++) {
    edge e = g[v][i];
    if (!dfs(e.to, cost + e.cost)) {
      return false;
    }
  }

  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    int l, r, d;
    cin >> l >> r >> d;
    g[l].push_back(edge{r, d});
    g[r].push_back(edge{l, -d});
  }

  fill(d, d + N + 1, INF);
  for (int i = 1; i <= N; i++) {
    if (visit[i]) {
      continue;
    }

    d[i] = 0;
    if (!dfs(i, 0)) {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
  return 0;
}