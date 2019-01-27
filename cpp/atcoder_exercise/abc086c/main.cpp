#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// - 移動できる条件
//   - 2点間の移動距離が時間以内であること
//   - 距離が偶数の場合は時間も偶数、奇数の場合は時間も奇数であること
int main() {
  int N;
  cin >> N;

  int prevT = 0;
  int prevX = 0;
  int prevY = 0;
  bool can = true;

  for (int i = 0; i < N; i++) {
    int t, x, y;
    cin >> t >> x >> y;

    int diffTime = t - prevT;
    int dist = abs(x - prevX) + abs(y - prevY); // 2点間の移動距離

    if (diffTime < dist || (diffTime % 2) != (dist % 2)) {
      can = false;
      break;
    }

    prevT = t;
    prevX = x;
    prevY = y;
  }

  if (can) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
