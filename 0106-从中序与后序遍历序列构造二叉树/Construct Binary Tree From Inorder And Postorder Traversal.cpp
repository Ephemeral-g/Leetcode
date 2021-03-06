#include <vector>
#include <unordered_map>
using std::unordered_map;
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
	TreeNode* buildTree(const vector<int>& inorder, const vector<int>& postorder) {
		size_t size = inorder.size();
		for (size_t i = 0; i < size; ++i) {
			m_inorder[inorder[i]] = i;
		}
		return buildTree(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
	}

	TreeNode* buildTree(const vector<int>& inorder, const vector<int>& postorder, int in_left, int in_right, int post_left, int post_right) {
		if (post_left > post_right) {
			return nullptr;
		}
		TreeNode *root = new TreeNode(postorder[post_right]);
		int in_mid = m_inorder[postorder[post_right]];
		int left_num = in_mid - in_left;
		root->left = buildTree(inorder, postorder, in_left, in_mid-1, post_left, post_left+left_num-1);
		root->right = buildTree(inorder, postorder, in_mid+1, in_right, post_left+left_num, post_right-1);
		return root;
	}

private:
	unordered_map<int, int> m_inorder;
};