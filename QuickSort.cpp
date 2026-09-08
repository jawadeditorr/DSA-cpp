#include <iostream>
#include <vector>
using namespace std;

// Partition function
int partition(vector<int> &arr, int low, int high) {

    int pivot = arr[high]; // Last element as pivot
    int i = low - 1;

    for (int j = low; j < high; j++) {

        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);

    return i + 1;
}

// Quick Sort function
void quickSort(vector<int> &arr, int low, int high) {

    if (low < high) {

        int pivotIndex = partition(arr, low, high);

        // Left side
        quickSort(arr, low, pivotIndex - 1);

        // Right side
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() {

    vector<int> arr = {8, 4, 7, 2, 1, 9, 3};

    quickSort(arr, 0, arr.size() - 1);

    cout << "Sorted Array: ";

    for (int x : arr) {
        cout << x << " ";
    }

    return 0;
}