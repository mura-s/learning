#include <iostream>
#include <string>
using namespace std;

void printArray(int a[], int n) {
    string sep = "";
    for (int i = 0; i < n; i++) {
        cout << sep << a[i];
        sep = " ";
    }
    cout << endl;
}

void insertionSort(int a[], int n) {
    printArray(a, n);

    for (int i = 1; i < n; i++) {
        int v = a[i];
        int j = i - 1;

        while (j >= 0 && v < a[j]) {
            a[j+1] = a[j];
            j--;
        }

        a[j+1] = v;

        printArray(a, n);
    }
}

int main() {
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    insertionSort(a, n);
}
