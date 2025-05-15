#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if (root == nullptr) return nullptr;
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        if (root->left == nullptr && root->right == nullptr && root->val == 0) {
            return nullptr;
        }
        return root;
    }
};


void printTree(TreeNode* root) {
    if (!root) return;
    printTree(root->left);
    cout << root->val << " ";
    printTree(root->right);
}

int main() {
    // Build example tree:
    //       1
    //      / \
    //     0   1
    //    /   / \
    //   0   0   1
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(0, new TreeNode(0), nullptr);
    root->right = new TreeNode(1, new TreeNode(0), new TreeNode(1));

    Solution solution;
    TreeNode* pruned = solution.pruneTree(root);

    cout << "In-order traversal of pruned tree: ";
    printTree(pruned);
    cout << endl;

    return 0;
}
