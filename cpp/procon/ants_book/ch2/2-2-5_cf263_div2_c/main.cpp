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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  ll sum = 0;
  priority_queue<ll, vector<ll>, greater<ll>> pq;
  for (int i = 0; i < N; i++) {
    ll ai;
    cin >> ai;
    pq.push(ai);
    sum += ai;
  }

  ll ans = 0;
  ll last = 0;
  while (!pq.empty()) {
    ans += sum;
    ll f = pq.top();
    pq.pop();
    sum -= f;
    ans += f;
    last = f;
  }
  ans -= last;

  cout << ans << endl;
  return 0;
}