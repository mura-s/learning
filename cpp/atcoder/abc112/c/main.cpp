#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct point {
  int x;
  int y;
  int h;
};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;
  vector<point> vec;
  for (int i = 0; i < N; i++) {
    int x, y, h;
    cin >> x >> y >> h;
    vec.push_back(point{x, y, h});
  }

  point ans{};
  for (int cx = 0; cx <= 100; cx++) {
    for (int cy = 0; cy <= 100; cy++) {
      bool ok = true;
      int H = 0;

      for (int i = 0; i < vec.size(); i++) {
        if (vec[i].h != 0) {
          H = vec[i].h + abs(vec[i].x - cx) + abs(vec[i].y - cy);
        }
      }

      for (int i = 0; i < vec.size(); i++) {
        int hi = H - abs(vec[i].x - cx) - abs(vec[i].y - cy);
        if (vec[i].h == 0) {
          if (hi > 0) {
            ok = false;
          }
        } else {
          if (hi != vec[i].h) {
            ok = false;
          }
        }
      }

      if (ok) {
        ans.x = cx;
        ans.y = cy;
        ans.h = H;
        goto BREAK;
      }
    }
  }

BREAK:
  cout << ans.x << " " << ans.y << " " << ans.h << "\n";
  return 0;
}