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

int A, B, C;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> A >> B >> C;

  if (A < C && C < B) {
    cout << "Yes" << endl;
  } else if (B < C && C < A) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}