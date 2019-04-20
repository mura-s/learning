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

int N;
string S;
int K;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> S >> K;

  char c = S[K - 1];
  for (int i = 0; i < N; i++) {
    if (c == S[i]) {
      cout << c;
    } else {
      cout << '*';
    }
  }
  cout << endl;
  return 0;
}