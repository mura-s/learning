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

int N, M, C;
vector<int> B;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M >> C;
  B.resize(M);
  for (int i = 0; i < M; i++) {
    cin >> B[i];
  }

  int ans = 0;
  for (int i = 0; i < N; i++) {
    vector<int> A(M);
    for (int j = 0; j < M; j++) {
      cin >> A[j];
    }

    int sum = C;
    for (int j = 0; j < M; j++) {
      sum += (A[j] * B[j]);
    }

    if (sum > 0) {
      ans++;
    }
  }

  cout << ans << endl;
  return 0;
}