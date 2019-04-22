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
// const int INF = 2000000000;
// const ll MOD = 1000000007;

ll N;
vector<ll> A, B, C;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  A.resize(N);
  for (ll i = 0; i < N; i++) {
    cin >> A[i];
  }
  sort(A.begin(), A.end());
  B.resize(N);
  for (ll i = 0; i < N; i++) {
    cin >> B[i];
  }
  sort(B.begin(), B.end());
  C.resize(N);
  for (ll i = 0; i < N; i++) {
    cin >> C[i];
  }
  sort(C.begin(), C.end());

  ll ans = 0;
  for (ll i = 0; i < N; i++) {
    ll bi = B[i];
    ll a_num = lower_bound(A.begin(), A.end(), bi) - A.begin();
    ll c_num = N - (upper_bound(C.begin(), C.end(), bi) - C.begin());
    ans += (a_num * c_num);
  }

  cout << ans << endl;
  return 0;
}