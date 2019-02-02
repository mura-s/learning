#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;

  string ans = "";
  switch (N) {
  case 22:
    ans = "Christmas Eve Eve Eve";
    break;
  case 23:
    ans = "Christmas Eve Eve";
    break;
  case 24:
    ans = "Christmas Eve";
    break;
  case 25:
    ans = "Christmas";
    break;
  }

  cout << ans << endl;
  return 0;
}