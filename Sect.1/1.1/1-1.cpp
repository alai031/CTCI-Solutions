#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isUnique(string s){
    if (s.length() > 128)
        return false;
    
    vector<bool> charSet(128);
    for (int i = 0; i < s.length(); ++i){
        if (charSet[int(s[i])])
            return false;
        charSet[int(s[i])] = true;
    }
    
    return true;
}

int main()
{
    string a = "helo";
    if (isUnique(a))
        cout << "Unique";
    else
        cout << "Not unique";

    return 0;
}