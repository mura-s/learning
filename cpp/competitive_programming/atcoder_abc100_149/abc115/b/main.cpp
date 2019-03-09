#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> vec;
  for (int i = 0; i < N; i++) {
    int tmp;
    cin >> tmp;
    vec.push_back(tmp);
  }
  sort(vec.rbegin(), vec.rend());

  int ans = vec[0] / 2;
  for (int i = 1; i < N; i++) {
    ans += vec[i];
  }

  cout << ans << endl;
  return 0;
}