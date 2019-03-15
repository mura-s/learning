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

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
  return a.second < b.second;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, M;
  cin >> N >> M;
  vector<pair<int, int>> ab;
  for (int i = 0; i < M; ++i) {
    int ai, bi;
    cin >> ai >> bi;
    ab.push_back(make_pair(ai, bi));
  }
  sort(ab.begin(), ab.end(), cmp);

  int ans = 0, end = 0;
  for (int i = 0; i < M; ++i) {
    if (end <= ab[i].first) {
      end = ab[i].second;
      ++ans;
    }
  }

  cout << ans << endl;
  return 0;
}