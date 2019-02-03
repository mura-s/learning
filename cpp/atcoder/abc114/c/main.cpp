#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string nums[3] = {"3", "5", "7"};
int N;

bool is753Num(int n) {
  if (n > N) {
    return false;
  }

  bool exist3 = false;
  bool exist5 = false;
  bool exist7 = false;

  while (n != 0) {
    int lastDidit = n % 10;
    if (lastDidit == 3) {
      exist3 = true;
    } else if (lastDidit == 5) {
      exist5 = true;
    } else if (lastDidit == 7) {
      exist7 = true;
    }

    n /= 10;
  }

  return exist3 && exist5 && exist7;
}

int solve(string &s) {
  if (s.size() >= 9) {
    return 0;
  }

  int count = 0;
  for (int i = 0; i < 3; i++) {
    string sNext = s + nums[i];
    if (is753Num(stoi(sNext))) {
      count++;
    }
    count += solve(sNext);
  }

  return count;
}

int main() {
  cin >> N;

  string s = "";
  cout << solve(s) << endl;
  return 0;
}