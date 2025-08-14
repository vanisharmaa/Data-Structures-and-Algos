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

// BRUTE FORCE
vector<vector<int>> allRootToLeafBrute(TreeNode *root)
{
    // your code goes here
    vector<vector<int>> output;
    if (!root)
        return output;
    // helper(root, output);
    vector<vector<int>> leftOutput = allRootToLeafBrute(root->left);
    vector<vector<int>> rightOutput = allRootToLeafBrute(root->right);
    int lSize = leftOutput.size(), rSize = rightOutput.size();
    if (lSize == 0 && rSize == 0)
    {
        vector<int> vec;
        vec.push_back(root->val);
        output.push_back(vec);
        return output;
    }
    for (int i = 0; i < lSize; i++)
    {
        leftOutput[i].insert(leftOutput[i].begin(), root->val);
        output.push_back(leftOutput[i]);
    }
    for (int i = 0; i < rSize; i++)
    {
        rightOutput[i].insert(rightOutput[i].begin(), root->val);
        output.push_back(rightOutput[i]);
    }
    return output;
}

void helper(TreeNode *root, vector<int> &path, vector<vector<int>> &output)
{
    if (!root)
        return;
    path.push_back(root->val);
    // If leaf node → save path
    if (!root->left && !root->right)
    {
        output.push_back(path);
    }
    else
    {
        // Otherwise go deeper
        helper(root->left, path, output);
        helper(root->right, path, output);
    }
    // Backtrack
    path.pop_back();
}

vector<vector<int>> allRootToLeaf(TreeNode *root)
{
    vector<vector<int>> output;
    if (!root)
        return output;
    vector<int> path;
    helper(root, path, output);
    return output;
}

int main()
{
    // TreeNode *root = new TreeNode(1);
    // root->right = new TreeNode(2);
    // root->right->left = new TreeNode(3);
    // root->right->left->right = new TreeNode(4);

    // TreeNode *root = new TreeNode(1);
    // root->left = new TreeNode(2);
    // root->left->right = new TreeNode(5);
    // root->left->right->left = new TreeNode(7);
    // root->right = new TreeNode(3);
    // root->right->right = new TreeNode(4);

    // TreeNode *root = new TreeNode(1);
    // root->left = new TreeNode(2);
    // root->right = new TreeNode(3);
    // root->left->left = new TreeNode(4);
    // root->left->right = new TreeNode(5);
    // root->right->left = new TreeNode(6);
    // root->right->right = new TreeNode(7);

    // TreeNode *root = new TreeNode(1);
    // root->right = new TreeNode(2);
    // root->right->right = new TreeNode(3);

    // root->right = new TreeNode(2);
    // root->right->right = new TreeNode(3);

    TreeNode *root = new TreeNode(20);
    root->left = new TreeNode(8);
    root->right = new TreeNode(22);

    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);

    root->right->right = new TreeNode(25);

    root->left->right->left = new TreeNode(10);
    root->left->right->right = new TreeNode(14);

    // Get the top view
    vector<vector<int>> output = allRootToLeaf(root);

    // Print the paths
    for (int i = 0; i < output.size(); i++)
    {
        for (int j = 0; j < output[i].size(); j++)
        {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
