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

string S;
int s_len;

long dfs(int idx, int bit) {
  if (idx == s_len - 1) {
    long sum = 0;
    int last = 0;
    for (int i = 0; i < s_len - 1; ++i) {
      if ((bit & (1 << i)) > 0) {
        sum += stol(S.substr(last, i + 1 - last));
        last = i + 1;
      }
    }
    sum += stol(S.substr(last));
    return sum;
  }

  return dfs(idx + 1, bit) + dfs(idx + 1, bit | (1 << idx));
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> S;
  s_len = S.size();

  cout << dfs(0, 0) << endl;
  return 0;
}