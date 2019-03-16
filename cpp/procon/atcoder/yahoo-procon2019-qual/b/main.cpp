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
  int a[3] = {};
  int b[3] = {};
  for (int i = 0; i < 3; ++i) {
    cin >> a[i] >> b[i];
  }
  bool can = false;

  int order[6][3] = {{0, 1, 2}, {0, 2, 1}, {1, 0, 2},
                     {1, 2, 0}, {2, 0, 1}, {2, 1, 0}};

  for (int o = 0; o < 6; ++o) {
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < 2; ++j) {
        for (int k = 0; k < 2; ++k) {
          int x[6];
          if (i == 0) {
            x[0] = a[order[o][0]];
            x[1] = b[order[o][0]];
          } else {
            x[0] = b[order[o][0]];
            x[1] = a[order[o][0]];
          }

          if (j == 0) {
            x[2] = a[order[o][1]];
            x[3] = b[order[o][1]];
          } else {
            x[2] = b[order[o][1]];
            x[3] = a[order[o][1]];
          }

          if (k == 0) {
            x[4] = a[order[o][2]];
            x[5] = b[order[o][2]];
          } else {
            x[4] = b[order[o][2]];
            x[5] = a[order[o][2]];
          }

          if (x[1] == x[2] && x[3] == x[4]) {
            can = true;
            goto BREAK;
          }
        }
      }
    }
  }

BREAK:
  if (can) {
    cout << "YES"
         << "\n";
  } else {
    cout << "NO"
         << "\n";
  }
  return 0;
}