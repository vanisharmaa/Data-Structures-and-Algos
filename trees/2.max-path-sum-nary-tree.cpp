#include <iostream>
#include <vector>
using namespace std;

class TreeNode
{
public:
    int val;
    vector<TreeNode *> children;

    TreeNode(int _val)
    {
        val = _val;
    }
};

int maxPathHelper(TreeNode *root, int &maxi)
{
    if (!root)
        return 0;
    int ans = root->val;
    int maxi1 = 0, maxi2 = 0;
    int maxChildAns = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        int sum = maxPathHelper(root->children[i], maxi);
        if (sum > maxi1)
        {
            maxi2 = maxi1;
            maxi1 = sum;
            ans = root->val + maxi1 + maxi2;
        }
        maxChildAns = max(maxChildAns, max(sum, 0));
    }
    maxi = max(maxi, ans);
    return root->val + maxChildAns;
}
int maxPathSum(TreeNode *root)
{
    int maxi = -1e8;
    maxPathHelper(root, maxi);
    return maxi;
}

int main()
{
    // Constructing the N-ary tree:
    // TreeNode* root = new TreeNode(1);
    // TreeNode* node2 = new TreeNode(2);
    // TreeNode* node3 = new TreeNode(3);
    // TreeNode* node4 = new TreeNode(4);
    // TreeNode* node5 = new TreeNode(5);
    // TreeNode* node6 = new TreeNode(6);

    // // Build connections
    // node3->children.push_back(node5);
    // node3->children.push_back(node6);

    // root->children.push_back(node3);
    // root->children.push_back(node2);
    // root->children.push_back(node4);

    // TreeNode* root = new TreeNode(-10);
    // TreeNode* node1 = new TreeNode(20);
    // TreeNode* node2 = new TreeNode(-5);
    // TreeNode* node3 = new TreeNode(-15);
    // TreeNode* node4 = new TreeNode(-25);
    // TreeNode* node5 = new TreeNode(30);

    // node1->children.push_back(node4);  // 20 → -25
    // node1->children.push_back(node5);  // 20 → 30

    // root->children.push_back(node1);
    // root->children.push_back(node2);
    // root->children.push_back(node3);

    TreeNode *root = new TreeNode(-1);
    TreeNode *node1 = new TreeNode(-2);
    TreeNode *node2 = new TreeNode(10);
    TreeNode *node3 = new TreeNode(-3);
    TreeNode *node4 = new TreeNode(-4);
    TreeNode *node5 = new TreeNode(-5);
    TreeNode *node6 = new TreeNode(100);

    node4->children.push_back(node5);
    node4->children.push_back(node6);
    node2->children.push_back(node4);

    root->children.push_back(node1);
    root->children.push_back(node2);
    root->children.push_back(node3);

    // Traversal
    vector<int> preorderTraversal;
    int maxPathSumVal = maxPathSum(root);
    cout << "maxPathSum: " << maxPathSumVal << endl;

    return 0;
}
