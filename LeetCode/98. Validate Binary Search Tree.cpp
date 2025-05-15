#include <iostream>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool validateBSTHelper(TreeNode* node, long long minVal, long long maxVal) {
    if (!node) return true;
    if (node->val <= minVal || node->val >= maxVal) return false;
    return validateBSTHelper(node->left, minVal, node->val) &&
           validateBSTHelper(node->right, node->val, maxVal);
}

bool isValidBST(TreeNode* root) {
    return validateBSTHelper(root, LONG_MIN, LONG_MAX);
}

int main() {
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    cout << (isValidBST(root) ? "Valid BST" : "Invalid BST") << endl;

    root->right->left = new TreeNode(0);  // This will invalidate the BST

    cout << (isValidBST(root) ? "Valid BST" : "Invalid BST") << endl;

    return 0;
}
