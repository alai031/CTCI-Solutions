#include <iostream>
#include <vector>

using namespace std;


int countWays(int n, vector<int> v){
    if (n < 0)
        return 0;
    else if (n == 0)
        return 1;
    else if (v[n] > -1)
        return v[n];
    else{
        v[n] = countWays(n-1, v) + countWays(n-2, v) + countWays(n-3, v);
        return v[n];
    }
}

int countWays(int n){
    vector<int> v(n+1, -1);
    return countWays(n, v);
}

int main()
{
    cout<< "The number of ways is: " << countWays(7) << endl;

    return 0;
}