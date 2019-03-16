#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> vec;
  for (int i = 0; i < M; i++) {
    int tmp = 0;
    cin >> tmp;
    vec.push_back(tmp);
  }
  sort(vec.begin(), vec.end());

  vector<int> diffs;
  for (int i = 1; i < M; i++) {
    int diff = abs(vec[i] - vec[i - 1]);
    diffs.push_back(diff);
  }
  sort(diffs.begin(), diffs.end());

  for (int i = 1; i < N; i++) {
    if (diffs.size() == 0) {
      break;
    }
    diffs.pop_back();
  }

  int ans = 0;
  for (auto &d : diffs) {
    ans += d;
  }

  cout << ans << endl;
  return 0;
}