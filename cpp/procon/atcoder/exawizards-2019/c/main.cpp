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
#include <unordered_map>
#include <vector>
using namespace std;
typedef long long ll;

int N, Q;
string s;
vector<char> t, d;

// posにいるゴーレムが0に到達するかどうか
bool check0(int pos) {
  for (int i = 0; i < Q; i++) {
    char c = s[pos];
    if (c == t[i]) {
      d[i] == 'L' ? pos-- : pos++;
    }

    if (pos == 0) {
      return true;
    } else if (pos == N + 1) {
      return false;
    }
  }
  return false;
}

// posにいるゴーレムがN+1に到達するかどうか
bool checkN1(int pos) {
  for (int i = 0; i < Q; i++) {
    char c = s[pos];
    if (c == t[i]) {
      d[i] == 'L' ? pos-- : pos++;
    }

    if (pos == 0) {
      return false;
    } else if (pos == N + 1) {
      return true;
    }
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> Q;
  cin >> s;
  s = "x" + s + "x"; // 0, N+1に番兵をつける
  t.resize(Q);
  d.resize(Q);
  for (int i = 0; i < Q; i++) {
    cin >> t[i] >> d[i];
  }

  // 0に到着するゴーレムの内、一番右のindexを求める
  int ansL = 0;
  int l = 0, r = N + 1;
  while (true) {
    if (r - l <= 1) {
      ansL = l;
      break;
    }

    int mid = (l + r) / 2;
    if (check0(mid)) {
      l = mid;
    } else {
      r = mid;
    }
  }

  // N+1に到着するゴーレムの内、一番左のindexを求める
  int ansR = N + 1;
  l = 0, r = N + 1;
  while (true) {
    if (r - l <= 1) {
      ansR = r;
      break;
    }

    int mid = (l + r) / 2;
    if (checkN1(mid)) {
      r = mid;
    } else {
      l = mid;
    }
  }

  cout << ansR - ansL - 1 << endl;
  return 0;
}