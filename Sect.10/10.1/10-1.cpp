#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& a, vector<int>& b, int lastA, int lastB){
    int indexA = lastA-1;
    int indexB = lastB-1;
    int indexMerged = lastA + lastB - 1;
    
    while (indexB >= 0){
        if (indexA >= 0 && a[indexA] > b[indexB]){
            a[indexMerged] = a[indexA];
            --indexA;
        }
        else{
            a[indexMerged] = b[indexB];
            --indexB;
        }
        --indexMerged;
    }
}

int main()
{
    vector<int> a = {20, 24, 28, 34, 0, 0, 0, 0, 0, 0};
    
    vector<int> b = {3, 5, 6, 12, 15, 32};
    
    merge(a, b, a.size()-b.size(), b.size());
    
    for (int i = 0; i < a.size(); ++i){
        cout << a[i] << endl;
    }

    return 0;
}