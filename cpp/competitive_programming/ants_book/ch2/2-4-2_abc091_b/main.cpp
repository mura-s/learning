#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
typedef long long ll;

int N, M;
unordered_map<string, int> s_map, t_map;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  for (int i = 0; i < N; i++) {
    string tmp;
    cin >> tmp;
    s_map[tmp]++;
  }
  cin >> M;
  for (int i = 0; i < M; i++) {
    string tmp;
    cin >> tmp;
    t_map[tmp]++;
  }

  int ans = 0;
  for (auto &p : s_map) {
    ans = max(ans, p.second - t_map[p.first]);
  }

  cout << ans << endl;
  return 0;
}