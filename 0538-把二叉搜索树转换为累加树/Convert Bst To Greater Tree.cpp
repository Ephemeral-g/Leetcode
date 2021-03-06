
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
	TreeNode* convertBST(TreeNode* root) {
		if (root != nullptr) {
			convertBST(root->right);
			count += root->val;
			root->val = count;
			convertBST(root->left);
		}
		return root;
	}
	// 方法二
	TreeNode* convertBST(TreeNode* root) {
		TreeNode* node = root;

		while (node != nullptr) {
			if (node->right == nullptr) {  // 当不存在右子树时，处理当前节点
				count += node->val;
				node->val = count;
				node = node->left;
			}
			else {
				TreeNode* tmp = node->right;  // 找到右子树的最左节点
				while (tmp->left != nullptr && tmp->left != node) {
					tmp = tmp->left;
				}
				if (tmp->left == nullptr) {  // 当该节点的左节点为空时
					tmp->left = node;  // 指向当前节点(node)
					node = node->right;  // 遍历右子树
				}
				else {  // 右子树已经遍历完成, 处理当前节点
					tmp->left = nullptr;
					count += node->val;
					node->val = count;
					node = node->left;  // 遍历左子树
				}
			}
		}
		return root;
	}
private:
	int count{ 0 };
};