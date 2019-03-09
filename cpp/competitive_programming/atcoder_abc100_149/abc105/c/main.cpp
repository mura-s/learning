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
  int N;
  cin >> N;
  string str = "";

  while (N != 0) {
    int r = N % 2;
    if (r < 0) {
      r += 2;
    }

    N = (N - r) / -2;
    str += (char)('0' + r);
  }

  reverse(str.begin(), str.end());
  if (str == "") {
    str = "0";
  }
  cout << str << endl;
  return 0;
}