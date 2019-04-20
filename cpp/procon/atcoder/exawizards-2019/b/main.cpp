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

int N;
string s;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  cin >> s;

  int r = 0, b = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'R') {
      r++;
    } else if (s[i] == 'B') {
      b++;
    }
  }

  if (r > b) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}