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
  int A, B;
  cin >> A >> B;

  if (B % A == 0) {
    cout << A + B << endl;
  } else {
    cout << B - A << endl;
  }

  return 0;
}