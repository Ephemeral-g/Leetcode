#include <algorithm>
using std::max;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
 
class Solution {
public:
	int depth(TreeNode *root) {
		if (root == nullptr) {
			return 0;
		}
		int left = depth(root->left);
		int right = depth(root->right);
		count = max(count, (left + right + 1));
		return max(left, right) + 1;
	}

	int diameterOfBinaryTree(TreeNode* root) {
		depth(root);
		return count - 1;
	}
private:
	int count{ 1 };
};