#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int>& a, int x){
    int low = 0;
    int high = a.size()-1;
    int mid;
    
    while (low <= high){
        mid = (low + high) / 2;
        if (x < a[mid])
            high = mid-1;
        else if (x > a[mid])
            low = mid+1;
        else
            return mid;
    }
    
    return -1;
}

int main()
{
    vector<int> a = {3, 5, 7, 8, 9, 10, 13};
    
    cout << "The index is " << binarySearch(a, 9);

    return 0;
}