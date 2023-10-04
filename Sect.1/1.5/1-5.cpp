#include <iostream>

using namespace std;

bool oneEditReplace(string s1, string s2){
    bool foundDifference = false;
    for (int i = 0; i < s1.length(); ++i){
        if (s1[i] != s2[i]){
            if (foundDifference)
                return false;
            foundDifference = true;
        }
    }
    return true;
}

bool oneEditInsert(string s1, string s2){
    int index1 = 0;
    int index2 = 0;
    while (index1 < s1.length() && index2 < s2.length()){
        if (s1[index1] != s2[index2]){
            if (index1 != index2){
                return false;
            }
            index2++;
        }
        else{
            index1++;
            index2++;
        }
    }
    return true;
}

bool oneEditAway(string first, string second){
    if (first.length() == second.length()){
        return oneEditReplace(first, second);
    }
    else if (first.length() + 1 == second.length()){
        return oneEditInsert(first, second);
    }
    else if (first.length() - 1 == second.length()){
        return oneEditInsert(second, first);
    }
    return false;
}

int main()
{
    if (oneEditAway("pales", "pale"))
        cout << "TRUE" << endl;
    else
        cout << "FALSE" << endl;

    return 0;
}