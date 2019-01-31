#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  string s = "abc";
  string sub = s.substr(3);

  cout << s.length() << endl;
  cout << sub << endl;
  return 0;
}