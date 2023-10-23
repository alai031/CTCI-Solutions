#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;

string sortChars(string s){
    sort(s.begin(), s.end());
    return s;
}

void sort(string array[], int size){
    unordered_map<string, vector<string>> mapList;
    for (int i = 0; i < size; ++i){
        string key = sortChars(array[i]);
        if (mapList.count(key))
            mapList.at(key).push_back(array[i]);
        else{
            vector<string> l{array[i]};
            mapList.insert({key, l});
        }
    }
    
    int index = 0;
    
    for (auto it = mapList.begin(); it != mapList.end(); ++it){
        vector<string> v = it->second;
        for (int j = 0; j < v.size(); ++j){
            array[index] = v[j];
            ++index;
        }
    }
    
}

int main()
{
    string arr[] = {"apple", "crab", "task", "bat", "barc", "tab", "kats", "pleap"};

    sort(arr, sizeof(arr)/sizeof(arr[0]));
    
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); ++i){
        cout << arr[i] << endl;
    }

    return 0;
}