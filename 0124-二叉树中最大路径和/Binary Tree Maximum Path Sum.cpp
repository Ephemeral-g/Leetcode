#include <algorithm>
using std::max;

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
    int maxSum(TreeNode* root) {
        if (root == nullptr) {
			return 0;
		}
		int left = max(0, maxSum(root->left));
		int right = max(0, maxSum(root->right));
		result = max(result, (left + right + root->val));
		return max(left, right) + root->val;
    }

	int maxPathSum(TreeNode* root) {
        maxSum(root);
        return result;
	}
private:
	int result{ INT_MIN };
};