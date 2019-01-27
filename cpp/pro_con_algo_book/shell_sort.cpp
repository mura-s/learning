#include <iostream>
#include <vector>
using namespace std;

void printArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << endl;
    }
}

int insertionSort(int a[], int n, int g) {
    int cnt = 0;

    for (int i = g; i < n; i++) {
        int v = a[i];
        int j = i - g;

        while (j >= 0 && v < a[j]) {
            a[j + g] = a[j];
            j -= g;
            cnt++;
        }

        a[j + g] = v;
    }

    return cnt;
}

int shellSort(int a[], int n) {
    int cnt = 0;

    vector<int> g;
    g.push_back(1);
    for (int i = 4; i < n; i = 3 * i + 1) {
        g.push_back(i);
    }

    int m = g.size();
    cout << m << endl;

    for (int i = m - 1; i >= 0; i--) {
        if (i != m - 1) cout << " ";
        cout << g.at(i);

        cnt += insertionSort(a, n, g.at(i));
    }
    cout << endl;

    return cnt;
}

int main() {
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int cnt = shellSort(a, n);

    cout << cnt << endl;
    printArray(a, n);
}
