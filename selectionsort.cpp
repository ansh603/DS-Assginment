#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        int minIndex = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if(minIndex != i) {
            int temp = arr[minIndex];
            arr[minIndex] = arr[i];
            arr[i] = temp;
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
    int arr[] = {34,45,11,99,77,66,55,33};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Array after sorting \n";
    printArray(arr, n);

    selectionSort(arr, n);

    cout << "Array before sorting \n";
    printArray(arr, n);

    return 0;
}
