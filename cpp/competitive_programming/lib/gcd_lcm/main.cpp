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

long gcd(long a, long b) {
  if (a < b) {
    return gcd(b, a);
  }

  while (a % b != 0) {
    long tmp = b;
    b = a % b;
    a = tmp;
  }
  return b;
}

long lcm(long a, long b) { return a * b / gcd(a, b); }

int main() {
  long a = 10;
  long b = 2;

  cout << gcd(a, b) << endl;
  cout << lcm(a, b) << endl;
  return 0;
}