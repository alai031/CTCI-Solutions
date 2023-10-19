#include <iostream>
#include <vector>

using namespace std;

int binarySearchRecursive(vector<int>& a, int x, int low, int high){
    if (low > high)
        return -1;
    
    int mid = (low + high) / 2;
    
    if (x < a[mid])
        return binarySearchRecursive(a, x, low, mid-1);
    else if (x > a[mid])
        return binarySearchRecursive(a, x, mid+1, high);
    else
        return mid;
}

int main()
{
    vector<int> a = {3, 5, 7, 8, 9, 10, 13};
    
    cout << "The index is " << binarySearchRecursive(a, 9, 0, a.size()-1);

    return 0;
}