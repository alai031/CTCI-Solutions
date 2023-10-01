#include <iostream>
#include <vector>

using namespace std;

int getCharNumber(char c){
    int a = int('a');
    int z = int('z');
    int val = int(c);
    if (a <= val && val <= z)
        return val-a;
    return -1;
}

vector<int> buildCharFrequencyTable(string a){
    vector<int> table(int('z') - int('a') + 1);
    for (int i = 0; i < a.size(); ++i){
        int x = getCharNumber(a[i]);
        if (x != -1)
            table[x]++;
    }
    return table;
}

bool checkMaxOneOdd(vector<int> table){
    bool foundOdd = false;
    for (int j = 0; j < table.size(); ++j){
        if (table[j] % 2 == 1){
            if (foundOdd)
                return false;
            foundOdd = true;
        }
    }
    return true;
}

bool isPermutationOfPalindrome(string a){
    vector<int> table = buildCharFrequencyTable(a);
    return checkMaxOneOdd(table);
}

int main()
{
    string a = "tact coa";
    if (isPermutationOfPalindrome(a))
        cout << "Is permutation of palindrome";
    else
        cout << "Not permutation of palindrome";

    return 0;
}