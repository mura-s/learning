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

int A, B, K;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> A >> B >> K;

  int n = A > B ? A : B;

  int cnt = 0;
  for (int i = n; i >= 1; i--) {
    if (A % i == 0 && B % i == 0) {
      cnt++;
    }

    if (cnt == K) {
      cout << i << endl;
      return 0;
    }
  }

  return 0;
}