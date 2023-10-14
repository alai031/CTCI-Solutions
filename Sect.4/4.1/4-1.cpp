#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct node {
    int val;
    bool visited;
};

bool existRoute(vector<vector<node>> g, int start, int end){
    vector<bool> v(g.size()); //tracks if a node has already been visited
    queue<int> q;
    
    v[start] = true;
    q.push(start);
    int u;
    while (!q.empty()){
        u = q.front();
        q.pop();
        if (u == end)
            return true;
        else{
            for (int j = 0; j < g[u].size(); ++j){
                int k = g[u][j].val;
                if (v[k] == false){
                    v[k] = true;
                    q.push(k);
                }
            }
        }
    }
    
    return false;
    
}

node makeNode(int val){
    node a;
    a.val = val;
    a.visited = false;
    return a;
}

int main()
{
    vector<vector<node>> g;
    for (int i = 0; i < 6; ++i){
        vector<node> f;
        g.push_back(f);
    }
    
    g[0].push_back(makeNode(5));
    g[0].push_back(makeNode(4));
    g[0].push_back(makeNode(1));
    g[1].push_back(makeNode(4));
    g[1].push_back(makeNode(3));
    g[2].push_back(makeNode(1));
    g[3].push_back(makeNode(2));
    g[3].push_back(makeNode(4));
    
    for (int i = 0; i < g.size(); ++i){
        cout << i << ": ";
        for (int j = 0; j < g[i].size(); ++j){
            cout << g[i][j].val << " ";
        }
        cout << endl;
    }

    if (existRoute(g, 1, 2))
        cout << "There exists a route" << endl;
    else
        cout << "No route" << endl;

    return 0;
}