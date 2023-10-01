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

bool isPermutationOfPalindrome(string a){
    int countOdd = 0;
    vector<int> table(int('z') - int('a') + 1);
    for (int i = 0; i < a.size(); ++i){
        int x = getCharNumber(a[i]);
        if (x != -1){
            table[x]++;
            if (table[x] % 2 == 1){
                countOdd++;
            }
            else
                countOdd--;
        }
    }
    return countOdd <= 1;
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
