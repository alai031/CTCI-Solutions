#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int row;
    int col;
    Point(int r, int c) : row(r), col(c) {}
};

bool getPath(vector<vector<bool>> maze, int row, int col, vector<Point*>& path, vector<Point*>& failedPoints){
    if (col < 0 || row < 0 || !maze[row][col]){
        return false;
    }
    
    Point* p = new Point(row, col);
    
    for (int i = 0; i < failedPoints.size(); ++i){
        if (failedPoints[i]->row == row && failedPoints[i]->col == col)
            return false;
    }
    
    bool isAtOrigin = (row == 0) && (col == 0);
    
    if (isAtOrigin || getPath(maze, row, col-1, path, failedPoints) || getPath(maze, row - 1, col, path, failedPoints)) {
        path.push_back(p);
        return true;
    }
    
    failedPoints.push_back(p);
    return false;
}

vector<Point*> getPath(vector<vector<bool>> maze){
    vector<Point*> noPath;
    if (maze.size() == 0)
        return noPath;
    vector<Point*> path;
    vector<Point*> failedPoints;
    if (getPath(maze, maze.size()-1, maze[0].size()-1, path, failedPoints)){
        return path;
    }
    return noPath;
}

int main()
{
    vector<vector<bool>> v{
        {true, true, true},
        {true, false, true},
        {false, true, true},
        {true, true, true},
    };
    
    for (int i = 0; i < v.size(); ++i){
        for (int j = 0; j < v[i].size(); ++j){
            if (v[i][j])
                cout << "true ";
            else
                cout << "false ";
        }
        cout << endl;
    }
    
    vector<Point*> ans = getPath(v);
    for(int k = 0; k < ans.size(); ++k){
        cout << ans[k]->row << "," << ans[k]->col << endl;
    }

    return 0;
}