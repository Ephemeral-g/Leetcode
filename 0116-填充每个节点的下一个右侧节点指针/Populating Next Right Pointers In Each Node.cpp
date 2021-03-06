#include <queue>
using std::queue;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    // 方法一
    Node* connect(Node* root) {
        if (root == nullptr) {
            return nullptr;
        }
        connectTwoNode(root->left, root->right);
        return root;
    }

    void connectTwoNode(Node* node1, Node* node2) {
        if (node1 == nullptr || node2 == nullptr) {
            return ;
        }
        node1->next = node2;
        connectTwoNode(node1->left, node1->right);
        connectTwoNode(node1->right, node2->left);
        connectTwoNode(node2->left, node2->right);
    }
	
	// 方法二
	Node* connect(Node* root) {
		if (root == nullptr) {
			return nullptr;
		}
		queue<Node*> qe;
		qe.emplace(root);

		while (!qe.empty()) {
			size_t size = qe.size();  // 同层节点数量

			for (size_t i = 0; i < size; ++i) {
				Node *node = qe.front();
				qe.pop();
				if (i < size - 1) {
					node->next = qe.front();
				}

				// 下一层
				if (node->left != nullptr) {
					qe.emplace(node->left);
				}
				if (node->right != nullptr) {
					qe.emplace(node->right);
				}
			}
		}
		return root;
	}
	
	// 方法三
	Node* connect(Node* root) {
		if (root == nullptr) {
			return nullptr;
		}
		Node *prev = root;
		while (prev->left != nullptr) {
			Node *node = prev;  // 更新下层节点的next指针
			while (node != nullptr) {
				node->left->next = node->right;
				if (node->next != nullptr) {
					node->right->next = node->next->left;
				}
				node = node->next;
			}
			prev = prev->left;
		}
		return root;
	}
};