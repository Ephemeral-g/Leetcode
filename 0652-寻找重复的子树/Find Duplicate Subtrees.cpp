#include <vector>
#include <string>
#include <unordered_map>
using std::string;
using std::vector;
using std::unordered_map;
using std::to_string;

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
	vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
		vector<TreeNode*> res;
		traverse(root, res);
		return res;
	}

	string traverse(TreeNode* root, vector<TreeNode*> &result) {
		if (root == nullptr) {
			return "#";
		}

		string left = traverse(root->left, result);
		string right = traverse(root->right, result);

		string subtree = left + "," + right + "," + to_string(root->val);

		auto iter = m_map.find(subtree);
		if (iter == m_map.end()) {
			m_map.emplace(subtree, 1);
		}
		else {
			if (iter->second == 1) {
				result.emplace_back(root);
			}
			++iter->second;
		}
		return subtree;
	}

private:
	unordered_map<string, int> m_map;
};