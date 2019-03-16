#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int dp[101][76];

int main() {
  int N;
  cin >> N;
  map<int, int> mp;
  for (int i = 2; i <= N; i++) {
    int n = i;
    for (int p = 2; p <= N; p++) {
      while (n % p == 0) {
        mp[p]++;
        n /= p;
      }
    }
  }

  vector<int> nums;
  for (auto p : mp) {
    nums.push_back(p.second);
  }
  int len = nums.size();

  dp[0][1] = 1;
  for (int i = 0; i < len; i++) {
    for (int d1 = 1; d1 <= 75; d1++) {
      for (int d2 = 1; d2 <= 75; d2++) {
        if (d1 * d2 <= 75 && nums[i] >= d2 - 1) {
          dp[i + 1][d1 * d2] += dp[i][d1];
        }
      }
    }
  }

  cout << dp[len][75] << endl;
  return 0;
}