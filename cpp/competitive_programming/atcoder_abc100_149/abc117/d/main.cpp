#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  long N, K;
  cin >> N >> K;
  vector<long> an;
  for (long i = 0; i < N; i++) {
    long tmp = 0;
    cin >> tmp;
    an.push_back(tmp);
  }

  long bitCount[65] = {};
  for (long a : an) {
    long i = 1;
    while (a != 0) {
      long d = a % 2;
      bitCount[i] += d;
      a /= 2;
      i++;
    }
  }

  // Kの桁数
  long K2 = K;
  long kbit = 0;
  while (K2 != 0) {
    K2 /= 2;
    kbit++;
  }

  // 上の桁から条件を満たすようにXを決めて行く
  // 0 <= X <= K
  long X = 0;
  for (long i = kbit; i >= 1; i--) {
    long lastBit = 0;
    if (bitCount[i] <= N / 2) {
      long nextVal = (2 * X + 1) << (i - 1);
      if (nextVal <= K) {
        lastBit = 1;
      }
    }
    X = 2 * X + lastBit;
  }

  long fMax = 0;
  for (long i = 0; i < N; i++) {
    fMax += X ^ an[i];
  }
  cout << fMax << endl;

  return 0;
}