
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
	// 方法一
    void flatten(TreeNode* root) {
		if (root == nullptr) {
			return;
		}

		flatten(root->left);
		flatten(root->right);

		TreeNode *node = root->right;
		root->right = root->left;
		root->left = nullptr;
		while (root->right != nullptr) {
			root = root->right;
		}
		root->right = node;
    }
	
	// 方法二
	void flatten(TreeNode* root) {
		if (root == nullptr) {
			return;
		}
		while (root != nullptr) {
			if (root->left != nullptr) {
				TreeNode *left = root->left;
				TreeNode *right = left;
				while (right->right != nullptr) {
					right = right->right;
				}
				right->right = root->right;
				root->right = root->left;
				root->left = nullptr;
			}
			root = root->right;
		}
	}
};