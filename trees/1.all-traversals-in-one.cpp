#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class TreeNode {
    public:
        int val;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int data) {
            val=data;
            left=NULL;
            right=NULL;
        }
};

void getAllTraversals(TreeNode* root, vector<int>& pre, vector<int>& in, vector<int>& post) {
    if (!root) return;
    stack<pair<TreeNode*, int>> st;
    st.push({root, 1});
    while(!st.empty()) {
        pair<TreeNode*, int> top = st.top();
        switch(top.second) {
            case 1:
                pre.push_back(top.first->val);
                st.top().second++;
                top.second++;
                if (top.first->left) st.push({top.first->left, 1});
                break;
            case 2:
                in.push_back(top.first->val);
                st.top().second++;
                top.second++;
                if (top.first->right) st.push({top.first->right, 1});
                break;
            case 3:
                post.push_back(top.first->val);
                st.pop();
        }
    }
}

int main() {
    TreeNode* root = new TreeNode(3);
    TreeNode* newLeft = new TreeNode(9);
    TreeNode* newRight = new TreeNode(20);
    root->left = newLeft;
    root->right = newRight;
    TreeNode* newLeft2 = new TreeNode(15);
    TreeNode* newRight2 = new TreeNode(7);
    root->right->left = newLeft2;
    root->right->right = newRight2;
    vector<int> pre, in, post;
    getAllTraversals(root, pre, in, post);
    cout << "pre: ";
    for(int i=0; i < pre.size(); i++) {
        cout << pre[i] << " ";
    }
    cout << endl << "in: ";
    for(int i=0; i < in.size(); i++) {
        cout << in[i] << " ";
    }
    cout << endl << "post: ";
    for(int i=0; i < post.size(); i++) {
        cout << post[i] << " ";
    }
    cout << endl;
    return 0;
}