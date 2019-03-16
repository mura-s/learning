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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;

  if (N == 1) {
    cout << "Hello World" << endl;
  } else {
    int A, B;
    cin >> A >> B;
    cout << A + B << endl;
  }
  return 0;
}