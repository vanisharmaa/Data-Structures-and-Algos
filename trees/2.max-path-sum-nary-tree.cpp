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

int maxPathHelper(TreeNode* root, int& maxPath) {
    if (!root)
        return 0;

    int maxThroughCurrent = root->val;

    // To store the top two maximum child path sums
    int firstMaxChildSum = 0, secondMaxChildSum = 0;

    // To return the best single child path sum upward
    int bestChildPath = 0;

    for (int i = 0; i < root->children.size(); i++) {
        int childPathSum = maxPathHelper(root->children[i], maxPath);

        // Update the top two child path sums
        if (childPathSum > firstMaxChildSum) {
            secondMaxChildSum = firstMaxChildSum;
            firstMaxChildSum = childPathSum;

            // Update maxThroughCurrent only when firstMax is updated
            maxThroughCurrent = root->val + firstMaxChildSum + secondMaxChildSum;
        }

        // Track the max one-sided path to return upward
        bestChildPath = max(bestChildPath, max(childPathSum, 0));
    }

    // Update the global maximum path sum if current is greater
    maxPath = max(maxPath, maxThroughCurrent);

    // Return the best one-sided path sum including current node
    return root->val + bestChildPath;
}

int maxPathSum(TreeNode* root) {
    int maxPath = -1e8;
    maxPathHelper(root, maxPath);
    return maxPath;
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
