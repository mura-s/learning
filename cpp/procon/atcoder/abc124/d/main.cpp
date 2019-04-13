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

int N, K;
string S;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> K;
  cin >> S;

  int ans = 0;
  queue<int> q;

  int sum = 0;
  int n = 0; // 連続した同じ値の数
  int k = 0; // 0に変わった数
  bool flag = (S[0] == '0');

  int i = 0;
  while (i < N) {
    char c = S[i];
    while (c == S[i]) {
      n++;
      i++;
    }
    if (c == '0') {
      k++;
      if (k > K) {
        if (!flag) {
          int f1 = q.front();
          q.pop();
          sum -= f1;
        }
        int f2 = q.front();
        q.pop();
        sum -= f2;
        flag = false;
      }
    }

    q.push(n);
    sum += n;
    n = 0;
    ans = max(ans, sum);
  }

  cout << ans << endl;
  return 0;
}