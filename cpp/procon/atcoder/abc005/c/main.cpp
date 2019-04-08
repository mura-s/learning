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

int T, N, M;
vector<int> A, B;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> T >> N;
  A.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  cin >> M;
  B.resize(M);
  for (int i = 0; i < M; i++) {
    cin >> B[i];
  }

  if (N < M) {
    cout << "no" << endl;
    return 0;
  }

  bool ans = true;
  int a_idx = N - 1;
  for (int i = M - 1; i >= 0; i--) {
    int bi = B[i];
    bool ok = false;
    for (int j = a_idx; j >= 0; j--) {
      int ai = A[j];
      if (bi < ai) {
        continue;
      }
      if (bi - ai <= T) {
        ok = true;
        a_idx = j - 1;
        break;
      }
    }

    if (!ok) {
      ans = false;
      break;
    }
  }

  if (ans) {
    cout << "yes" << endl;
  } else {
    cout << "no" << endl;
  }
  return 0;
}
