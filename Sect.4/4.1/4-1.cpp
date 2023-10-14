#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
    int val;
    bool visited;
};

Node* makeNode(int val){
    Node* n = new Node();
    n->val = val;
    n->visited = false;
    return n;
}

bool existRoute(vector<vector<Node*>> g, Node* start, Node* end){
    queue<Node*> q;
    start->visited = true;
    q.push(start);
    while (!q.empty()){
        Node* k = q.front();
        q.pop();
        if (k == end)
            return true;
        else{
            int l = k->val;
            for (int i = 0; i < g[l].size(); ++i){
                if (g[l][i]->visited == false){
                    g[l][i]->visited = true;
                    q.push(g[l][i]);
                }
            }
        }
    }
    return false;
}

int main()
{
    vector<vector<Node*>> g;
    for (int i = 0; i < 6; ++i){
        vector<Node*> n;
        g.push_back(n);
    }

    Node* a = makeNode(0);
    Node* b = makeNode(1);
    Node* c = makeNode(2);
    Node* d = makeNode(3);
    Node* e = makeNode(4);
    Node* f = makeNode(5);
    
    g[0].push_back(f);
    g[0].push_back(e);
    g[0].push_back(b);
    g[1].push_back(e);
    g[1].push_back(d);
    g[2].push_back(b);
    g[3].push_back(c);
    g[3].push_back(e);
    
    for (int i = 0; i < g.size(); ++i){
        cout << i << ": ";
        for (int j = 0; j < g[i].size(); ++j){
            cout << g[i][j]->val << " ";
        }
        cout << endl;
    }
    
    if (existRoute(g, b, c)){
        cout << "There exists a route";
    }
    else
        cout << "There does not exist a route";
    
    return 0;
}