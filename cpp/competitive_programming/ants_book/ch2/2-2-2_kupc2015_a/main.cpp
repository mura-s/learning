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
  int T;
  cin >> T;
  vector<string> ss(T);
  for (int i = 0; i < T; i++) {
    cin >> ss[i];
  }

  for (int i = 0; i < T; i++) {
    string s = ss[i];
    int ans = 0, j = 0, size = s.size();
    while (j + 4 < size) {
      if (s.substr(j, 5) == "kyoto" || s.substr(j, 5) == "tokyo") {
        ans++;
        j += 5;
      } else {
        j++;
      }
    }
    cout << ans << endl;
  }

  return 0;
}