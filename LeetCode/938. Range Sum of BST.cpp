#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int rangeSumBST(TreeNode* root, int low, int high) {
    if (!root) return 0;
    
    int sum = 0;
    if (root->val >= low && root->val <= high) {
        sum += root->val;
    }
    
    if (root->val > low) {
        sum += rangeSumBST(root->left, low, high);
    }
    if (root->val < high) {
        sum += rangeSumBST(root->right, low, high);
    }
    
    return sum;
}

int main() {
    // Construct BST
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right->right = new TreeNode(18);
    
    int low = 7, high = 15;
    cout << "Range Sum BST (" << low << ", " << high << "): " << rangeSumBST(root, low, high) << endl;
    
    return 0;
}
