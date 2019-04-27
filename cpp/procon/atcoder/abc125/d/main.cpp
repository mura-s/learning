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

ll N;
vector<ll> A;
bool zero = false;
int zero_idx = 0;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  A.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    if (A[i] == 0) {
      zero = true;
      zero_idx = i;
    }
  }

  ll ans = 0;
  if (zero) {
    for (int i = 0; i < zero_idx; i++) {
      ans += abs(A[i]);
    }
    if (zero_idx != N) {
      int num_minus = 0;
      for (int i = zero_idx; i < N; i++) {
        if (A[i] < 0) {
          num_minus++;
        }
      }

      vector<ll> abs_A;
      for (int i = zero_idx; i < N; i++) {
        abs_A.push_back(abs(A[i]));
      }
      if (num_minus % 2 == 0) {
        for (int i = 0; i < abs_A.size(); i++) {
          ans += abs_A[i];
        }
      } else {
        sort(abs_A.begin(), abs_A.end());
        ans -= abs_A[0];
        for (int i = 1; i < abs_A.size(); i++) {
          ans += abs_A[i];
        }
      }
    }
  } else {
    int num_minus = 0;
    for (int i = 0; i < N; i++) {
      if (A[i] < 0) {
        num_minus++;
      }
    }
    vector<ll> abs_A(N);
    for (int i = 0; i < N; i++) {
      abs_A[i] = abs(A[i]);
    }
    if (num_minus % 2 == 0) {
      for (int i = 0; i < N; i++) {
        ans += abs_A[i];
      }
    } else {
      sort(abs_A.begin(), abs_A.end());
      ans -= abs_A[0];
      for (int i = 1; i < N; i++) {
        ans += abs_A[i];
      }
    }
  }

  cout << ans << endl;
  return 0;
}