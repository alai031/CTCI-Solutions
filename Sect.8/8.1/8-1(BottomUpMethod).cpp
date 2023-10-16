#include <iostream>
#include <vector>

using namespace std;

int countWays(int n){
    if (n < 0)
        return 0;
        
    vector<int> v(n+1);
    v[0] = 1;
    v[1] = 1;
    v[2] = 2;
    
    for (int i = 3; i <= n; ++i){
        v[i] = v[i-1] + v[i-2] + v[i-3];
    }
    
    return v[n];
}

int main()
{
    cout << "The number of ways is: " << countWays(7) << endl;

    return 0;
}