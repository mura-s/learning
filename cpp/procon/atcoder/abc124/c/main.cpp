#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
// const int INF = 2000000000;
// const ll MOD = 1000000007;

string S;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> S;

  // case 01...
  int min0 = 0;
  for (int i = 0; i < S.size(); i++) {
    if (i % 2 == 0) {
      if (S[i] == '1') {
        min0++;
      }
    } else {
      if (S[i] == '0') {
        min0++;
      }
    }
  }

  // case 10...
  int min1 = 0;
  for (int i = 0; i < S.size(); i++) {
    if (i % 2 == 0) {
      if (S[i] == '0') {
        min1++;
      }
    } else {
      if (S[i] == '1') {
        min1++;
      }
    }
  }

  cout << min(min0, min1) << endl;
  return 0;
}