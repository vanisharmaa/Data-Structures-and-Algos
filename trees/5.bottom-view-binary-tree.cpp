#include <iostream>
#include <vector>
#include <map>

using namespace std;

// TreeNode class representing each node in the binary tree
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

// Recursive function to fill the map with top view nodes
void feedMap(TreeNode *root, int row, int col, map<int, pair<int, int>> &mpp)
{
    if (!root)
        return;

    // If this column is not visited OR
    // if current node is at a higher level (smaller row), update the map
    if (mpp.find(col) == mpp.end() || row > mpp[col].first)
    {
        mpp[col] = {row, root->val}; // Store (row, value)
    }

    // Recurse for left and right subtrees with updated row and column
    feedMap(root->left, row + 1, col - 1, mpp);  // Move to left child: row + 1, col - 1
    feedMap(root->right, row + 1, col + 1, mpp); // Move to right child: row + 1, col + 1
}

vector<int> bottomView(TreeNode *root)
{
    vector<int> output;
    if (!root)
        return output;

    map<int, pair<int, int>> mpp; // map<column, (row, value)>
    feedMap(root, 0, 0, mpp);     // Start from root at row = 0, col = 0

    // Traverse the map to get bottom view nodes in left-to-right order
    for (auto &mp : mpp)
    {
        output.push_back(mp.second.second); // mp.second = {row, value}
    }

    return output;
}

int main()
{
    TreeNode *root = new TreeNode(20);
    root->left = new TreeNode(8);
    root->right = new TreeNode(22);

    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);

    root->right->right = new TreeNode(25);

    root->left->right->left = new TreeNode(10);
    root->left->right->right = new TreeNode(14);

    // Get the top view
    vector<int> output = bottomView(root);

    // Print the top view
    for (int i = 0; i < output.size(); i++)
    {
        cout << output[i] << " ";
    }
    cout << endl;

    return 0;
}
