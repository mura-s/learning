#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;

int main() {
  int N, K;
  cin >> N >> K;
  map<int, vector<int>> mp;
  for (int i = 0; i < N; i++) {
    int t, d;
    cin >> t >> d;
    mp[t].push_back(d);
  }

  // split into max values of each type and others
  vector<int> maxes, others;
  for (auto &p : mp) {
    vector<int> v = p.second;
    sort(v.rbegin(), v.rend());
    maxes.push_back(v[0]);
    for (int i = 1; i < v.size(); i++) {
      others.push_back(v[i]);
    }
  }

  // reverse sort
  sort(maxes.rbegin(), maxes.rend());
  sort(others.rbegin(), others.rend());

  // cumulative sum
  vector<ll> maxes_sum(N + 1, 0);
  for (int i = 0; i < maxes.size(); i++) {
    maxes_sum[i + 1] = maxes_sum[i] + maxes[i];
  }
  vector<ll> others_sum(N + 1, 0);
  for (int i = 0; i < others.size(); i++) {
    others_sum[i + 1] = others_sum[i] + others[i];
  }

  // find best k
  int kmax = min(K, (int)maxes.size());
  ll ans = 0;
  for (ll k = 1; k <= kmax; k++) {
    ll sum = maxes_sum[k] + others_sum[K - k] + k * k;
    ans = max(ans, sum);
  }
  cout << ans << endl;

  return 0;
}