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

string S;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> S;

  int zero_cnt = 0;
  int one_cnt = 0;
  for (int i = 0; i < S.size(); i++) {
    if (S[i] == '0') {
      zero_cnt++;
    } else {
      one_cnt++;
    }
  }

  if (zero_cnt == 0 || one_cnt == 0) {
    cout << 0 << endl;
  } else {
    if (zero_cnt < one_cnt) {
      cout << zero_cnt * 2 << endl;
    } else {
      cout << one_cnt * 2 << endl;
    }
  }

  return 0;
}