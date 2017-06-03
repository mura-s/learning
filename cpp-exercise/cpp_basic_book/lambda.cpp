#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    const int N = 16;
    vector<int> v;
    for (int i = 1; i <= N; i++) v.push_back(i);

    sort(v.begin(), v.end(),
            [](int lhs, int rhs)->bool {
                return lhs < rhs;
            }
    );

    for (auto i : v) cout << i << ", ";
    cout << endl;
}
