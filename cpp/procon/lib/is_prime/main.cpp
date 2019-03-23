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
// const long MOD = 1000000007;

bool is_prime(int x) {
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      return false;
    }
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a = 13;
  int b = 15;

  cout << is_prime(a) << endl;
  cout << is_prime(b) << endl;
  return 0;
}