#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string dream_rev = "maerd";
string dreamer_rev = "remaerd";
string erase_rev = "esare";
string eraser_rev = "resare";

bool start_with(string S, string prefix, int size) {
  return S.substr(0, size) == prefix;
}

int main() {
  string S;
  cin >> S;
  reverse(S.begin(), S.end());

  while (true) {
    if (S == "") {
      cout << "YES" << endl;
      break;
    }

    int len = S.length();
    if (len < 5) {
      cout << "NO" << endl;
      break;
    }

    if (start_with(S, dream_rev, 5) || start_with(S, erase_rev, 5)) {
      S = S.substr(5);
    } else if (start_with(S, eraser_rev, 6)) {
      S = S.substr(6);
    } else if (start_with(S, dreamer_rev, 7)) {
      S = S.substr(7);
    } else {
      cout << "NO" << endl;
      break;
    }
  }

  return 0;
}