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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string S;
  cin >> S;
  int s = stoi(S.substr(0, 4)) * 10000 + stoi(S.substr(5, 2)) * 100 +
          stoi(S.substr(8, 2));

  if (s <= 20190430) {
    cout << "Heisei" << endl;
  } else {
    cout << "TBD" << endl;
  }
  return 0;
}