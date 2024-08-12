#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {12,45,54,34,11,9};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Array before sorting \n";
    printArray(arr, n);

    insertionSort(arr, n);

    cout << "Array after sorting \n";
    printArray(arr, n);

    return 0;
}