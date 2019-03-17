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
const long MOD = 1000000007;

int N;
string S;
map<char, long> mp;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> S;
  for (int i = 0; i < N; i++) {
    mp[S[i]]++;
  }

  long ans = 1;
  for (auto &e : mp) {
    ans *= (e.second + 1);
    ans %= MOD;
  }
  ans--;

  cout << ans << endl;
  return 0;
}