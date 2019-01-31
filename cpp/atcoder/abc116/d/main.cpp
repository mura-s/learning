#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

typedef long long ll;

long point(vector<pair<int, long>> &vec) {
  unordered_set<int> set;
  long point = 0;
  for (auto &p : vec) {
    set.insert(p.first);
    point += p.second;
  }
  long size = set.size();
  return point + size * size;
}

int main() {
  int N, K;
  cin >> N >> K;
  vector<pair<int, long>> vec;
  for (int i = 0; i < N; i++) {
    int t, d;
    cin >> t >> d;
    vec.push_back(make_pair(t, d));
  }

  sort(vec.begin(), vec.end(),
       [](const pair<int, long> &p1, pair<int, long> &p2) {
         return p1.second > p2.second;
       });

  vector<pair<int, long>> resultVec;
  for (int i = 0; i < K; i++) {
    resultVec.push_back(make_pair(vec[i].first, vec[i].second));
  }
  long result = point(resultVec);

  int m[100001] = {};
  for (int i = K - 1; i >= 0; i--) {
    int type = vec[i].first;
    if (m[type] == 0) {
      m[type] = i;
      continue;
    }

    bool found = false;
    int cand = m[type];

    for (int j = K; j < N; j++) {
      int type2 = vec[j].first;
      if (type != type2) {
        pair<int, long> tmp = resultVec[cand];
        resultVec[cand] = vec[j];
        vec[j] = tmp;
        m[type2] = cand;
        found = true;
        break;
      }
    }

    if (found) {
      m[type] = i;
      long value = point(resultVec);
      if (value > result) {
        result = value;
      }
    }
  }

  cout << result << endl;
  return 0;
}