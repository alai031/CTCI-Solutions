#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void printLast10Lines(char* fileName){
    int k = 10;
    ifstream file(fileName);
    vector<string> L(10);
    int size = 0;
    
    while (file.peek() != EOF){
        getline(file, L[size % k]);
        ++size;
    }
    
    int start = 0;
    if (size > k)
        start = size % k;
    int count = min(k, size);
    
    for (int i = 0; i < count; ++i){
        cout << L[(start + i) % k] << endl;
    }

}

int main()
{
    printLast10Lines("example.txt");

    return 0;
}