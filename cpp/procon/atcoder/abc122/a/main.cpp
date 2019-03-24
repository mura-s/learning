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
typedef long long ll;
// const int INF = 2000000000;
// const ll MOD = 1000000007;

string b;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> b;

  if (b == "A") {
    cout << "T" << endl;
  } else if (b == "T") {
    cout << "A" << endl;
  } else if (b == "C") {
    cout << "G" << endl;
  } else if (b == "G") {
    cout << "C" << endl;
  }

  return 0;
}