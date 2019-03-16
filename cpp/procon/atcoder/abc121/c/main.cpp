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

long N, M;
vector<pair<long, long>> AB;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M;
  AB.resize(N);
  for (long i = 0; i < N; i++) {
    long ai, bi;
    cin >> ai >> bi;
    AB[i] = make_pair(ai, bi);
  }
  sort(AB.begin(), AB.end());

  long ans = 0;
  for (long i = 0; i < N; i++) {
    if (AB[i].second < M) {
      M -= AB[i].second;
      ans += (AB[i].first * AB[i].second);
    } else {
      ans += (AB[i].first * M);
      M = 0;
      break;
    }
  }

  cout << ans << endl;
  return 0;
}