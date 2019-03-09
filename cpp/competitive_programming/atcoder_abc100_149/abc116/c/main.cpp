#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N = 0;
int hs[110];
int MAX = 1000;

int min(int start, int end) {
  int m = MAX;
  for (int i = start; i <= end; i++) {
    if (hs[i] < m) {
      m = hs[i];
    }
  }
  return m;
}

int solve(int start, int end) {
  int count = 0;

  if (end - start < 1) {
    count += hs[start];
    hs[start] = 0;
    return count;
  }

  int m = min(start, end);
  if (m == 0) {
    for (int i = start; i <= end; i++) {
      if (hs[i] == 0) {
        count += solve(start, i - 1) + solve(i + 1, end);
        break;
      }
    }
  } else {
    for (int i = start; i <= end; i++) {
      hs[i] = hs[i] - m;
    }
    count += m + solve(start, end);
  }

  return count;
}

int main() {
  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> hs[i];
  }

  cout << solve(1, N) << endl;
  return 0;
}