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
  string S;
  long K;
  cin >> S >> K;
  char ans = '0';

  for (int i = 0; i < S.size(); ++i) {
    if (S[i] != '1') {
      ans = S[i];
      break;
    }

    --K;
    if (K == 0) {
      ans = S[i];
      break;
    }
  }

  cout << ans << endl;
  return 0;
}