#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string sortString(string s){
    sort(s.begin(), s.end());
    return s;
}

bool isPermutation(string a, string b){
    if (a.length() != b.length())
        return false;
    
    return (sortString(a) == sortString(b));
}

int main()
{
    string a = "age";
    string b = "gea";
    if (isPermutation(a, b))
        cout << "PERMUTATION";
    else
        cout << "NOT PERMUTATION";

    return 0;
}