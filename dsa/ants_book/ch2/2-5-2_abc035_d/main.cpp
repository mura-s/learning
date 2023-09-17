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
const ll INF = pow(2, 50);
const ll MAX_V = 100001;

struct edge {
  ll to, cost;
};
typedef pair<ll, ll> P; // firstは最短距離, secondは頂点の番号

vector<edge> G[MAX_V];
ll d[MAX_V];

vector<edge> G_rev[MAX_V];
ll d_rev[MAX_V];

ll N, M, T;
vector<ll> A;

// 蟻本参照
void dijkstra(ll s) {
  priority_queue<P, vector<P>, greater<P>> que;
  fill(d, d + N, INF);
  d[s] = 0;
  que.push(P(0, s));

  while (!que.empty()) {
    P p = que.top();
    que.pop();
    ll v = p.second;
    if (d[v] < p.first) {
      continue;
    }

    for (int i = 0; i < G[v].size(); i++) {
      edge e = G[v][i];
      if (d[e.to] > d[v] + e.cost) {
        d[e.to] = d[v] + e.cost;
        que.push(P(d[e.to], e.to));
      }
    }
  }
}

void dijkstra_rev(ll s) {
  priority_queue<P, vector<P>, greater<P>> que;
  fill(d_rev, d_rev + N, INF);
  d_rev[s] = 0;
  que.push(P(0, s));

  while (!que.empty()) {
    P p = que.top();
    que.pop();
    ll v = p.second;
    if (d_rev[v] < p.first) {
      continue;
    }

    for (ll i = 0; i < G_rev[v].size(); i++) {
      edge e = G_rev[v][i];
      if (d_rev[e.to] > d_rev[v] + e.cost) {
        d_rev[e.to] = d_rev[v] + e.cost;
        que.push(P(d_rev[e.to], e.to));
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M >> T;
  A.resize(N);
  for (ll i = 0; i < N; i++) {
    cin >> A[i];
  }
  for (ll i = 0; i < M; i++) {
    ll a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    G[a].push_back(edge{b, c});
    G_rev[b].push_back(edge{a, c});
  }

  dijkstra(0);
  dijkstra_rev(0);

  ll ans = 0;
  for (ll i = 0; i < N; i++) {
    if (d[i] == INF || d_rev[i] == INF) {
      continue;
    }
    ans = max(ans, A[i] * (T - d[i] - d_rev[i]));
  }
  cout << ans << endl;
  return 0;
}