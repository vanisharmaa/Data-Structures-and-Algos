#include <iostream>
#include <vector>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data)
    {
        val = data;
        left = NULL;
        right = NULL;
    }
};

void feedLeftBoundary(TreeNode *root, vector<int> &output)
{
    if (!root)
        return;
    if (!root->left && !root->right) return;
    output.push_back(root->val);
    if (!root->left) feedLeftBoundary(root->right, output);
    feedLeftBoundary(root->left, output);
}

void feedRightBoundary(TreeNode *root, vector<int> &output) {
    if (!root) return;
    if (!root->left && !root->right) return;
    output.push_back(root->val);
    if (!root->right) feedRightBoundary(root->left, output);
    feedRightBoundary(root->right, output);
}

void feedLeafNodes(TreeNode* root, vector<int>& output) {
    if(!root) return;
    if(!root->left && !root->right) output.push_back(root->val);
    feedLeafNodes(root->left, output);
    feedLeafNodes(root->right, output);
}

vector<int> boundary(TreeNode *root)
{
    // your code goes here
    vector<int> output;
    if (!root)
        return output;
    output.push_back(root->val);
    if (root->left)
        feedLeftBoundary(root->left, output);
    if(root->left || root->right) feedLeafNodes(root, output);
    vector<int> rightBoundary;
    if (root->right) feedRightBoundary(root->right, rightBoundary);
    if (rightBoundary.size() > 0) {
        reverse(rightBoundary.begin(), rightBoundary.end());
        output.insert(output.end(), rightBoundary.begin(), rightBoundary.end());
    }
    return output;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    // root->left = new TreeNode(2);
    // root->right = new TreeNode(3);

    // root->left->left = new TreeNode(4);
    // root->left->right = new TreeNode(5);
    // root->right->left = new TreeNode(6);
    // root->right->right = new TreeNode(7);

    // root->left->right = new TreeNode(9);

    // root->left->left->left = new TreeNode(6);
    // root->left->left->right = new TreeNode(5);

    // root->left->right->left = new TreeNode(3);
    // // skipping nulls in between
    // root->left->right->left->left = new TreeNode(7);
    // root->left->right->left->right = new TreeNode(8);

    vector<int> output = boundary(root);
    for (int i = 0; i < output.size(); i++)
    {
        cout << output[i] << " ";
    }
    cout << endl;

    return 0;
}