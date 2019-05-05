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
// const ll MOD = 1000000007;
// const int INF = 2000000000;

int N;
vector<int> X, Y;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  X.resize(N);
  Y.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> X[i] >> Y[i];
  }

  int mod = abs(X[0] + Y[0]) % 2;
  for (int i = 1; i < N; i++) {
    if (abs(X[i] + Y[i]) % 2 != mod) {
      cout << -1 << endl;
      return 0;
    }
  }

  int m = 0;
  vector<int> d;
  if (mod == 1) {
    m = 31;
    for (int i = m - 1; i >= 0; i--) {
      d.push_back(pow(2, i));
    }
  } else {
    m = 32;
    for (int i = m - 2; i >= 0; i--) {
      d.push_back(pow(2, i));
    }
    d.push_back(1);
  }

  vector<vector<char>> w(N);
  for (int i = 0; i < N; i++) {
    int xt = X[i], yt = Y[i];
    int x = 0, y = 0;
    vector<char> s(m);
    for (int j = 0; j < m; j++) {
      if (abs(x - xt) >= abs(y - yt)) {
        if (x >= xt) {
          x -= d[j];
          s[j] = 'L';
        } else {
          x += d[j];
          s[j] = 'R';
        }
      } else {
        if (y >= yt) {
          y -= d[j];
          s[j] = 'D';
        } else {
          y += d[j];
          s[j] = 'U';
        }
      }
    }
    w[i] = s;
  }

  // output
  cout << m << endl;
  for (int i = 0; i < d.size(); i++) {
    if (i != 0) {
      cout << " ";
    }
    cout << d[i];
  }
  cout << endl;
  for (auto &e : w) {
    for (auto &c : e) {
      cout << c;
    }
    cout << endl;
  }
  return 0;
}