#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& array, vector<int> helper, int low, int middle, int high){
    for (int i = low; i <= high; ++i){
        helper.at(i) = array.at(i);
    }
    
    int helperLeft = low;
    int helperRight = middle + 1;
    int current = low;
    
    while (helperLeft <= middle && helperRight <= high){
        if (helper.at(helperLeft) <= helper.at(helperRight)){
            array.at(current) = helper.at(helperLeft);
            helperLeft++;
        }
        else{
            array.at(current) = helper.at(helperRight);
            helperRight++;
        }
        current++;
    }
    
    int remaining = middle - helperLeft;
    for (int i = 0; i <= remaining; ++i){
        array.at(current + i) = helper.at(helperLeft + i);
    }
}

void mergesort(vector<int>& array, vector<int> helper, int low, int high){
    if (low < high) {
        int middle = (low + high) / 2;
        mergesort(array, helper, low, middle);
        mergesort(array, helper, middle+1, high);
        merge(array, helper, low, middle, high);
    }
}

void mergesort(vector<int>& array){
    vector<int> helper(array.size());
    mergesort(array, helper, 0, array.size()-1);
}

int main()
{
    vector<int> a = {5, 2, 3, 4, 1};
    mergesort(a);
    for (int i = 0; i < a.size(); ++i){
        cout << a[i] << endl;
    }

    return 0;
}