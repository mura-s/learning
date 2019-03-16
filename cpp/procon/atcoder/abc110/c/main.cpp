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

  string S, T;
  cin >> S >> T;
  bool can = true;

  map<char, char> s_map;
  map<char, char> t_map;

  for (int i = 0; i < S.size(); i++) {
    char si = S[i];
    char ti = T[i];

    if (s_map[si] != 0 && s_map[si] != ti) {
      can = false;
      break;
    }
    if (t_map[ti] != 0 && t_map[ti] != si) {
      can = false;
      break;
    }

    s_map[si] = ti;
    t_map[ti] = si;
  }

  if (can) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}