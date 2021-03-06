#include <unordered_map>
using std::unordered_map;

class Solution {
public:
	TreeNode* BuildTreeEx(const vector<int>& preorder, vector<int>& inorder, int pre_left, int pre_right, int in_left, int in_right) {
		if (pre_left > pre_right) {
			return nullptr;
		}
		// 前序遍历中第一个节点就是根节点
		int per_root = pre_left;
		// 定位中序遍历中根节点的位置
		int in_root = index[preorder[per_root]];
		
		TreeNode* root = new TreeNode(preorder[per_root]);
		// 获取左子树的数量
		int size_left = in_root - in_left;
		// 构建左子树
		root->left = BuildTreeEx(preorder, inorder, per_root + 1, per_root + size_left, in_left, in_root - 1);
		// 构建右子树
		root->right = BuildTreeEx(preorder, inorder, per_root + size_left + 1, pre_right, in_root + 1, in_right);
		return root;
	}

	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		size_t size = inorder.size();
		// 通过哈希表快速定位中序遍历中的根节点的位置
		for (size_t i = 0; i < size; ++i) {
			index[inorder[i]] = i;
		}
		return BuildTreeEx(preorder, inorder, 0, size-1, 0, size-1);
	}
private:
	unordered_map<int, int> index;
};