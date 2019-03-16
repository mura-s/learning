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

int A, B, C;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> A >> B >> C;

  int x = A + B;
  if (C <= x) {
    cout << B + C << endl;
  } else {
    cout << B + x + 1 << endl;
  }

  return 0;
}