#include <iostream>
#include <utility>
using namespace std;

void printArray(int a[], int n) {
    string sep = "";
    for (int i = 0; i < n; i++) {
        cout << sep << a[i];
        sep = " ";
    }
    cout << endl;
}

int bubbleSort(int a[], int n) {
    int numOfSwap = 0;
    bool flag = true;
    for (int i = 0; flag; i++) {
        flag = false;
        for (int j = n - 1; j > i; j--) {
            if (a[j - 1] > a[j]) {
                swap(a[j - 1], a[j]);
                numOfSwap++;
                flag = true;
            }
        }
    }
    return numOfSwap;
}

int main() {
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int numOfSwap = bubbleSort(a, n);

    printArray(a, n);
    cout << numOfSwap << endl;
}

