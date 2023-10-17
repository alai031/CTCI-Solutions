#include <iostream>
#include <algorithm>
#include <array>

using namespace std;

int partition(int arr[], int left, int right){
    int pivot = arr[(left + right) / 2];
    while (left <= right) {
        while (arr[left] < pivot)
            ++left;
        while (arr[right] > pivot)
            --right;
        if (left <= right) {
            swap(arr[left], arr[right]);
            ++left;
            --right;
        }
    }
    return left;
}

void quickSort(int arr[], int left, int right){
    int index = partition(arr, left, right);
    if (left < index - 1)
        quickSort(arr, left, index - 1);
    if (index < right) {
        quickSort(arr, index, right);
    }
}

int main()
{
    int arr[] = {3, 5, 6, 7, 2, 9, 4};
    quickSort(arr, 0, sizeof(arr) / sizeof(int) - 1);
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); ++i){
        cout << arr[i] << endl;
    }

    return 0;
}