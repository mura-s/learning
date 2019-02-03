#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  string S;
  cin >> S;

  int target = 753;
  int ans = INT_MAX;
  for (int i = 2; i < S.size(); i++) {
    string sub = S.substr(i - 2, 3);
    int x = stoi(sub);
    ans = min(ans, abs(x - target));
  }

  cout << ans << endl;
  return 0;
}