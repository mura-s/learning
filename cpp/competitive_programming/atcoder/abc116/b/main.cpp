#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
  int s;
  cin >> s;
  int m = 0;
  unordered_set<int> set;

  // i = 1
  int ai = s;
  set.insert(ai);

  // i > 1
  for (int i = 2; i <= 1000000; i++) {
    if (ai % 2 == 0) {
      ai = ai / 2;
    } else {
      ai = 3 * ai + 1;
    }

    if (set.find(ai) != set.end()) {
      m = i;
      break;
    }
    set.insert(ai);
  }

  cout << m << endl;
  return 0;
}