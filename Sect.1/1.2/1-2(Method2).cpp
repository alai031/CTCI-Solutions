#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isPermutation(string a, string b){
    if (a.length() != b.length())
        return false;
    
    vector<int> charCount(128);
    
    for (int i = 0; i < a.length(); ++i){
        int c = int(a[i]);
        ++charCount[c];
    }
    
    for (int j = 0; j < b.length(); ++j){
        int d = int(b[j]);
        --charCount[d];
        if (charCount[d] < 0)
            return false;
    }
    
    return true;
}

int main()
{
    string a = "resco";
    string b = "Cores";
    if (isPermutation(a, b))
        cout << "PERMUTATION";
    else
        cout << "NOT PERMUTATION";

    return 0;
}