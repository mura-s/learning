#include <algorithm>
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

int a, b, c, d, e;
int k;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> a >> b >> c >> d >> e;
  cin >> k;

  if (e - a <= k) {
    cout << "Yay!" << endl;
  } else {
    cout << ":(" << endl;
  }

  return 0;
}