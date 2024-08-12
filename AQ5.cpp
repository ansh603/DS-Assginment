#include <cstring> // For strcmp
using namespace std;

template <typename T>
long longinclude <iostream>
 calculateAddress(int rows, int cols, int baseAddress, int indexRow, int indexCol, bool isRowMajor) {
    int elementSize = sizeof(T);
    long long address;

    if (isRowMajor) {
        address = baseAddress + (indexRow * cols + indexCol) * elementSize;
    } else {
        address = baseAddres#s + (indexCol * rows + indexRow) * elementSize;
    }

    return address;
}

int main() {
    // Input type of array
    char type[10];
    cout << "Enter type of array (int, char, float): ";
    cin >> type;

    // Input size of array
    int rows, cols;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    // Input memory arrangement
    char arrangement[10];
    cout << "Enter memory arrangement (row-major or column-major): ";
    cin >> arrangement;
    bool isRowMajor = (strcmp(arrangement, "row-major") == 0);

    // Input base address
    int baseAddress;
    cout << "Enter base address of the array: ";
    cin >> baseAddress;

    // Input index of the element
    int indexRow, indexCol;
    cout << "Enter row index of the element: ";
    cin >> indexRow;
    cout << "Enter column index of the element: ";
    cin >> indexCol;

    // Calculate address
    long long address;
    if (strcmp(type, "int") == 0) {
        address = calculateAddress<int>(rows, cols, baseAddress, indexRow, indexCol, isRowMajor);
    } else if (strcmp(type, "char") == 0) {
        address = calculateAddress<char>(rows, cols, baseAddress, indexRow, indexCol, isRowMajor);
    } else if (strcmp(type, "float") == 0) {
        address = calculateAddress<float>(rows, cols, baseAddress, indexRow, indexCol, isRowMajor);
    } else {
        cout << "Unsupported type!" << endl;
        return 1;
    }

    // Output address
    cout << "The address of the element at (" << indexRow << ", " << indexCol << ") is: " << address << endl;

    return 0;
}