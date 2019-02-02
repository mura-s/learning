#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> vec;
  for (int i = 0; i < N; i++) {
    int tmp;
    cin >> tmp;
    vec.push_back(tmp);
  }
  sort(vec.begin(), vec.end());

  int ans = INT_MAX;
  for (int i = K - 1; i < N; i++) {
    int hmin = vec[i - K + 1];
    int hmax = vec[i];
    int diff = hmax - hmin;
    ans = min(ans, diff);
  }

  cout << ans << endl;
  return 0;
}