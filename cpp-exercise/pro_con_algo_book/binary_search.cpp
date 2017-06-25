#include <iostream>
using namespace std;

bool binarySearch(int s[], int n, int v) {
    int left = 0;
    int right = n;
    while (left < right) {
        int mid = (left + right) / 2;
        if (s[mid] == v) {
            return true;
        } else if (s[mid] < v) {
            left = mid + 1;
        } else if (s[mid] > v) {
            right = mid;
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    int s[n];
    for (int i = 0; i < n; i++) cin >> s[i];

    int q;
    cin >> q;
    int t[q];
    for (int i = 0; i < n; i++) cin >> t[i];

    int cnt = 0;
    for (int i = 0; i < q; i++) {
        if (binarySearch(s, n, t[i])) {
            cnt++;
        }
    }

    cout << cnt << endl;
}
