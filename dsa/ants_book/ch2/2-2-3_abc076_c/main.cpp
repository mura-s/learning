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

const string ur = "UNRESTORABLE";

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string S_d, T;
  cin >> S_d >> T;

  bool ok = false;
  string S = S_d;
  int t_size = T.size();

  for (int i = S_d.size() - 1; i >= t_size - 1; i--) {
    bool match = true;
    int j = i - t_size + 1, k = 0;
    while (k < t_size) {
      if (S_d[j] != T[k] && S_d[j] != '?') {
        match = false;
        break;
      }
      j++;
      k++;
    }

    if (match) {
      S.replace(i - t_size + 1, t_size, T);
      ok = true;
      break;
    }
  }

  if (ok) {
    for (int i = 0; i < S.size(); i++) {
      if (S[i] == '?') {
        S[i] = 'a';
      }
    }
    cout << S << endl;
  } else {
    cout << ur << endl;
  }
  return 0;
}