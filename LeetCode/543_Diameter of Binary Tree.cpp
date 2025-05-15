#include <iostream>
#include <algorithm>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    int res = 0;

public:
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return res;
    }

private:
    int dfs(TreeNode* root) {
        if (!root) return 0;

        int l = dfs(root->left);
        int r = dfs(root->right);

        res = max(res, l + r);
        return 1 + max(l, r);
    }
};

int main() {
  

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution solution;
    int result = solution.diameterOfBinaryTree(root);

    cout << "Diameter of the binary tree: " << result << endl;

    return 0;
}
