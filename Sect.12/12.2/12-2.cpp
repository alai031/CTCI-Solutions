#include <iostream>

using namespace std;

void reverse(char* str){
    char* end = str;
    char tmp;
    if (str){
        while (*end){
            ++end;
        }
        --end; 
        
        while (str < end){
            tmp = *str;
            *str = *end;
            *end = tmp;
            ++str;
            --end;
        }
    }
}

int main()
{
    string a = "hello";
    char* b = &a[0];
    reverse(b);
    for (int i = 0; i < a.size(); ++i){
        cout << b[i] << endl;
    }

    return 0;
}