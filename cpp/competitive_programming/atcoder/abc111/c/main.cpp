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

struct p {
  int cnt, v;
};

bool cmp(const p &p1, const p &p2) { return p1.cnt > p2.cnt; }

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;
  vector<p> odd_vec(100002); // with sentinel
  fill(odd_vec.begin(), odd_vec.end(), p{0, 0});
  vector<p> even_vec(100002); // with sentinel
  fill(even_vec.begin(), even_vec.end(), p{0, 0});

  for (int i = 1; i <= N; i++) {
    int vi;
    cin >> vi;
    if (i % 2 == 1) {
      odd_vec[vi].v = vi;
      odd_vec[vi].cnt++;
    } else {
      even_vec[vi].v = vi;
      even_vec[vi].cnt++;
    }
  }

  sort(odd_vec.begin(), odd_vec.end(), cmp);
  sort(even_vec.begin(), even_vec.end(), cmp);

  int odd_idx = 0;
  int even_idx = 0;
  if (odd_vec[odd_idx].v == even_vec[even_idx].v) {
    if (odd_vec[odd_idx].cnt > even_vec[even_idx].cnt) {
      even_idx++;
    } else if (odd_vec[odd_idx].cnt < even_vec[even_idx].cnt) {
      odd_idx++;
    } else { // odd_vec[odd_idx].cnt == even_vec[even_idx].cnt
      if (odd_vec[odd_idx + 1].cnt > even_vec[even_idx + 1].cnt) {
        odd_idx++;
      } else if (odd_vec[odd_idx + 1].cnt < even_vec[even_idx + 1].cnt) {
        even_idx++;
      } else {
        even_idx++; // or odd_idx++
      }
    }
  }

  int ans = 0;
  for (int i = 0; odd_vec[i].cnt != 0; i++) {
    if (i == odd_idx) {
      continue;
    }
    ans += odd_vec[i].cnt;
  }
  for (int i = 0; even_vec[i].cnt != 0; i++) {
    if (i == even_idx) {
      continue;
    }
    ans += even_vec[i].cnt;
  }
  cout << ans << endl;

  return 0;
}