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
  ios::sync_with_stdio(false);
  cin.tie(0);
  long X, Y;
  cin >> X >> Y;
  vector<long> as;

  long i = X;
  while (i <= Y) {
    as.push_back(i);
    i *= 2;
  }

  cout << as.size() << endl;
  return 0;
}