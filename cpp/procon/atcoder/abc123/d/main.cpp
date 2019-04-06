#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
// const int INF = 2000000000;
// const ll MOD = 1000000007;

ll X, Y, Z, K;
vector<ll> A, B, C;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  // input
  cin >> X >> Y >> Z >> K;
  A.resize(X);
  for (int i = 0; i < X; i++) {
    cin >> A[i];
  }
  sort(A.begin(), A.end(), greater<ll>());
  B.resize(Y);
  for (int i = 0; i < Y; i++) {
    cin >> B[i];
  }
  sort(B.begin(), B.end(), greater<ll>());
  C.resize(Z);
  for (int i = 0; i < Z; i++) {
    cin >> C[i];
  }
  sort(C.begin(), C.end(), greater<ll>());

  // AB
  vector<ll> AB(X * Y);
  for (int i = 0; i < X; i++) {
    for (int j = 0; j < Y; j++) {
      AB[i * Y + j] = A[i] + B[j];
    }
  }
  sort(AB.begin(), AB.end(), greater<ll>());

  // ABC
  ll max_ab = min(K, X * Y);
  vector<ll> ABC(K * Z);
  for (int i = 0; i < max_ab; i++) {
    for (int j = 0; j < Z; j++) {
      ABC[i * Z + j] = AB[i] + C[j];
    }
  }
  sort(ABC.begin(), ABC.end(), greater<ll>());

  // output
  for (int i = 0; i < K; i++) {
    cout << ABC[i] << endl;
  }

  return 0;
}