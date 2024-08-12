#include <iostream>
#include <cstring> 
using namespace std;

template <typename T>
long long calculateAddress3D(int rows, int cols, int depth, int baseAddress, int indexRow, int indexCol, int indexDepth, bool isRowMajor) {
    int elementSize = sizeof(T);
    long long address;

    if (isRowMajor) {
        address = baseAddress + ((indexRow * cols + indexCol) * depth + indexDepth) * elementSize;
    } else {
        address = baseAddress + ((indexDepth * rows + indexRow) * cols + indexCol) * elementSize;
    }

    return address;
}

int main() {
    
    char type[10];
    cout << "Enter type of array (int, char, float): ";
    cin >> type;

    
    int rows, cols, depth;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;
    cout << "Enter depth (number of layers): ";
    cin >> depth;

    
    char arrangement[10];
    cout << "Enter memory arrangement (row-major or column-major): ";
    cin >> arrangement;
    bool isRowMajor = (strcmp(arrangement, "row-major") == 0);

    int baseAddress;
    cout << "Enter base address of the array: ";
    cin >> baseAddress;

    
    int indexRow, indexCol, indexDepth;
    cout << "Enter row index of the element: ";
    cin >> indexRow;
    cout << "Enter column index of the element: ";
    cin >> indexCol;
    cout << "Enter depth index of the element: ";
    cin >> indexDepth;

    
    long long address;
    if (strcmp(type, "int") == 0) {
        address = calculateAddress3D<int>(rows, cols, depth, baseAddress, indexRow, indexCol, indexDepth, isRowMajor);
    } else if (strcmp(type, "char") == 0) {
        address = calculateAddress3D<char>(rows, cols, depth, baseAddress, indexRow, indexCol, indexDepth, isRowMajor);
    } else if (strcmp(type, "float") == 0) {
        address = calculateAddress3D<float>(rows, cols, depth, baseAddress, indexRow, indexCol, indexDepth, isRowMajor);
    } else {
        cout << "Unsupported type!" << endl;
        return 1;
    }

    
    cout << "The address of the element at (" << indexRow << ", " << indexCol << ", " << indexDepth << ") is: " << address << endl;

    return 0;
}