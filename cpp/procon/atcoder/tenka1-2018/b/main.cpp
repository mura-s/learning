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

int A, B, K;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> A >> B >> K;
  for (int i = 0; i < K; i++) {
    if (i % 2 == 0) {
      A /= 2;
      B += A;
    } else {
      B /= 2;
      A += B;
    }
  }

  cout << A << " " << B << endl;
  return 0;
}