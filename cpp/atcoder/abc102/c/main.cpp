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
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<long> bs;
  for (int i = 1; i <= N; ++i) {
    long tmp;
    cin >> tmp;
    bs.push_back(tmp - i);
  }
  sort(bs.begin(), bs.end());

  long median = bs[N / 2];

  long f = 0;
  for (auto &e : bs) {
    f += abs(e - median);
  }
  cout << f << endl;
  return 0;
}