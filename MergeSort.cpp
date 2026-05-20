#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int st, int mid, int end) {

    vector<int> temp;

    int i = st;       // Left subarray start
    int j = mid + 1;  // Right subarray start

    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
        }
    }

    while (i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }

    while (j <= end) {
        temp.push_back(arr[j]);
        j++;
    }

    for (int k = 0; k < temp.size(); k++) {
        arr[st + k] = temp[k];
    }
}

void mergeSort(vector<int> &arr, int st, int end) {

    if (st < end) {

        int mid = st + (end - st) / 2;

        mergeSort(arr, st, mid);       // Left half
        mergeSort(arr, mid + 1, end);  // Right half

        merge(arr, st, mid, end);      // Merge both halves
    }
}

int main() {

    vector<int> arr = {8, 3, 1, 7, 0, 10, 2};

    mergeSort(arr, 0, arr.size() - 1);

    cout << "Sorted Array: ";

    for (int x : arr) {
        cout << x << " ";
    }

    return 0;
}