#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {22,44,33,11,19,20,98,55};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Array before sorting \n";
    printArray(arr, n);

    bubbleSort(arr, n);

    cout << "Array after sorting  \n";
    printArray(arr, n);

    return 0;
}