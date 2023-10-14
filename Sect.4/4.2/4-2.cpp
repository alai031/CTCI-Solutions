#include <iostream>
#include <array>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

TreeNode* createMinimalBST(int arr[], int start, int end){
    if (start > end)
        return nullptr;
    int mid = (start + end) / 2;
    TreeNode* n = new TreeNode(arr[mid]);
    n->left = createMinimalBST(arr, start, mid-1);
    n->right = createMinimalBST(arr, mid+1, end);
    return n;
}

TreeNode* createMinimalBST(int array[], int size){
    return createMinimalBST(array, 0, size-1);
}

int main()
{
    int arr[] = {2, 4, 5, 9, 13, 16, 20, 42};
    TreeNode* root = createMinimalBST(arr, sizeof(arr) / sizeof(int));
    cout << root->val << endl;
    cout << root->left->val << endl;
    cout << root->left->left->val << endl;
    cout << root->left->right->val << endl;
    
    cout << root->right->val << endl;;
    cout << root->right->left->val << endl;
    cout << root->right->right->val << endl;
    cout << root->right->right->right->val << endl;

    return 0;
}