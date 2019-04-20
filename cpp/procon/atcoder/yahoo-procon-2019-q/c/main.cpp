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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  long K, A, B;
  cin >> K >> A >> B;

  // 1. 全てビスケットを叩く
  long ans1 = K + 1;

  // 2. ビスケット交換を繰り返す
  long ans2 = 1;
  long i = 0;
  while (true) {
    long a = 0;
    if (ans2 < A) {
      a = A - ans2;
    }
    long j = i + 2 + a;

    if (j <= K) {
      if (ans2 < A) {
        ans2 = A;
      }
      ans2 -= A;
      ans2 += B;
      i = j;
    } else {
      ans2 += K - i;
      break;
    }
  }

  long ans = max(ans1, ans2);
  cout << ans << "\n";
  return 0;
}