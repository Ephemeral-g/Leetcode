#include <vector>
using std::vector;

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
	TreeNode* constructMaximumBinaryTree(vector<int> &nums) {
		if (nums.size() == 0) {
			return nullptr;
		}
		return constructMaximumBinaryTree(nums, 0, nums.size());
	}

	TreeNode* constructMaximumBinaryTree(vector<int> &nums, size_t left, size_t right) {
		int maxNum{ -1 };
		size_t pos;
		
		for (size_t i = left; i < right; ++i) {
			if (nums.at(i) > maxNum) {
				pos = i;
				maxNum = nums.at(i);
			}
		}

		TreeNode *root = new TreeNode(maxNum);
		root->left = constructMaximumBinaryTree(nums, left, pos);
		root->right = constructMaximumBinaryTree(nums, pos + 1, right);
		return root;
	}
};