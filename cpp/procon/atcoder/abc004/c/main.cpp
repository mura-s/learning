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

int N;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  N = N % 30;
  int vals[6] = {1, 2, 3, 4, 5, 6};

  for (int i = 0; i < N; i++) {
    swap(vals[i % 5], vals[(i % 5) + 1]);
  }

  for (int i = 0; i < 6; i++) {
    cout << vals[i];
  }
  cout << endl;

  return 0;
}