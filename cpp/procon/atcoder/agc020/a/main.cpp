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

int N, A, B;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> A >> B;

  int diff = B - A;
  if (diff % 2 == 0) {
    cout << "Alice" << endl;
  } else {
    cout << "Borys" << endl;
  }

  return 0;
}