#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& arr, int left, int right){
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

void quickSort(vector<int>& arr, int left, int right){
    int index = partition(arr, left, right);
    if (left < index - 1)
        quickSort(arr, left, index - 1);
    if (index < right) {
        quickSort(arr, index, right);
    }
}

int main()
{
    vector<int> arr = {2, 1, 6, 4, 5};
    quickSort(arr, 0, arr.size()-1);
    for (int i = 0; i < arr.size(); ++i){
        cout << arr[i] << endl;
    }

    return 0;
}