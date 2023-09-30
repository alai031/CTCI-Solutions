#include <iostream>
#include <string>

using namespace std;

string replaceSpaces(string s, int trueLength){
    int index = s.length();
    
    for (int i = trueLength-1; i >= 0; --i){
        if (s[i] == ' '){
            s[index-1] = '0';
            s[index-2] = '2';
            s[index-3] = '%';
            index = index-3;
        }
        else{
            s[index-1] = s[i];
            index = index - 1;
        }
    }
    return s;
}

int main()
{
    string a = "Mr John Smith    ";
    cout << replaceSpaces(a, 13) << endl;

    return 0;
}