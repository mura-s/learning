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

int A, B;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> A >> B;

  int sum = 0;
  for (int i = 0; i < 2; i++) {
    if (A > B) {
      sum += A;
      A--;
    } else {
      sum += B;
      B--;
    }
  }
  cout << sum << endl;
  return 0;
}