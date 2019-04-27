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
// const ll MOD = 1000000007;
// const int INF = 2000000000;

int gcd(int a, int b) {
  if (a < b) {
    return gcd(b, a);
  }

  while (a % b != 0) {
    int tmp = b;
    b = a % b;
    a = tmp;
  }
  return b;
}

int N;
vector<int> A;
vector<int> cum_A;
vector<int> cum_rev_A;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  A.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  cum_A.resize(N, 0);
  cum_A[0] = A[0];
  for (int i = 1; i < N; i++) {
    cum_A[i] = gcd(cum_A[i - 1], A[i]);
  }
  cum_rev_A.resize(N, 0);
  cum_rev_A[0] = A[N - 1];
  for (int i = 1; i < N; i++) {
    cum_rev_A[i] = gcd(cum_rev_A[i - 1], A[N - i - 1]);
  }

  int ans = 0;
  for (int i = 0; i < N; i++) {
    if (i == 0) {
      ans = max(ans, cum_rev_A[N - 2]);
    } else if (i == N - 1) {
      ans = max(ans, cum_A[N - 2]);
    } else {
      ans = max(ans, gcd(cum_A[i - 1], cum_rev_A[N - i - 2]));
    }
  }

  cout << ans << endl;
  return 0;
}