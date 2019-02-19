#include <algorithm>
#include <boost/multiprecision/cpp_int.hpp>
#include <cassert>
#include <climits>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

int main() {
  boost::multiprecision::cpp_int a("12345678901234567890");
  boost::multiprecision::cpp_int b("2");

  cout << a * b << endl;
  return 0;
}