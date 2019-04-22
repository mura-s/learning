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

char A[10][10];
bool visit[10][10];

int num_land = 0;

int dfs(int i, int j) {
  if (visit[i][j] || A[i][j] == 'x') {
    return 0;
  }
  visit[i][j] = true;
  int sum = 1;

  if (i - 1 >= 0) {
    sum += dfs(i - 1, j);
  }
  if (i + 1 < 10) {
    sum += dfs(i + 1, j);
  }
  if (j - 1 >= 0) {
    sum += dfs(i, j - 1);
  }
  if (j + 1 < 10) {
    sum += dfs(i, j + 1);
  }

  return sum;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      cin >> A[i][j];
      if (A[i][j] == 'o') {
        num_land++;
      }
    }
  }
  num_land++;

  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      if (A[i][j] == 'x') {
        fill(visit[0], visit[10], false);
        A[i][j] = 'o';
        if (dfs(i, j) == num_land) {
          cout << "YES" << endl;
          return 0;
        }
        A[i][j] = 'x';
      }
    }
  }

  cout << "NO" << endl;
  return 0;
}
