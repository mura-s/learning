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
// const int INF = 2000000000;
// const ll MOD = 1000000007;

int A, B;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> A >> B;

  if (A <= 8 && B <= 8) {
    cout << "Yay!" << endl;
  } else {
    cout << ":(" << endl;
  }
  return 0;
}