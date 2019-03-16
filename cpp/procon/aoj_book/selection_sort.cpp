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

int selectionSort(int a[], int n) {
    int numOfSwap = 0;
    for (int i = 0; i < n; i++) {
        int minj = i;
        bool swapped = false;
        for (int j = i; j < n; j++) {
            if (a[j] < a[minj]) {
                minj = j;
                swapped = true;
            }
        }
        if (swapped) {
            swap(a[i], a[minj]);
            numOfSwap++;
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

    int numOfSwap = selectionSort(a, n);

    printArray(a, n);
    cout << numOfSwap << endl;
}

