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
  int H, W;
  cin >> H >> W;
  vector<vector<int>> a(H, vector<int>(W, 0));
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      int a_ij;
      cin >> a_ij;
      a[i][j] = a_ij;
    }
  }

  int N = 0;
  vector<int> y, x, y_dash, x_dash;

  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      if (a[i][j] % 2 != 0) {
        if (i != H - 1) {
          // not last row
          --a[i][j];
          ++a[i + 1][j];
          ++N;
          y.push_back(i + 1);
          x.push_back(j + 1);
          y_dash.push_back(i + 2);
          x_dash.push_back(j + 1);
        } else {
          // last row
          if (j != W - 1) {
            // not last column
            --a[i][j];
            ++a[i][j + 1];
            ++N;
            y.push_back(i + 1);
            x.push_back(j + 1);
            y_dash.push_back(i + 1);
            x_dash.push_back(j + 2);
          }
        }
      }
    }
  }

  cout << N << endl;
  for (int i = 0; i < N; ++i) {
    cout << y[i] << " " << x[i] << " " << y_dash[i] << " " << x_dash[i] << endl;
  }
  return 0;
}