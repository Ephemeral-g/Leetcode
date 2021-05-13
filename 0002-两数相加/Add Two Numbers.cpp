#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

struct ListNode 
{
	int val;
	ListNode *next;

	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution 
{
public:
	ListNode* addTwoNumbers(ListNode *l1, ListNode *l2) 
	{
		ListNode *head{ new ListNode(-1) };
		ListNode *node{ head };

		int carry{ 0 };  // 进位标志
		while (l1 != nullptr || l2 != nullptr) {
			int sum{ 0 };
			if (l1 != nullptr) {
				sum += l1->val;
				l1 = l1->next;
			}
			if (l2 != nullptr) {
				sum += l2->val;
				l2 = l2->next;
			}
			sum += carry;
			node->next = new ListNode(sum % 10);
			carry = sum / 10;
			node = node->next;
		}
		// 进位
		if (carry == 1) {
			node->next = new ListNode(1);
		}
		node = head->next;
		delete head;
		return node;
	}
};

// 类的成员函数
using addTwoNumbers = ListNode * (Solution::*)(ListNode*, ListNode*);

int main()
{
	Solution s;

	// 打印链表
	auto print = [](ListNode *head) {
		cout << "[";
		if (head == nullptr) {
			return;
		}

		while (head->next != nullptr) {
			cout << head->val << ", ";
			head = head->next;
		}

		cout << head->val << "]";
	};

	// 判断两个链表是否相同
	auto check = [](ListNode *l1, ListNode *l2) -> bool {
		while (l1 != nullptr && l2 != nullptr) {
			if (l1->val == l2->val) {
				l1 = l1->next;
				l2 = l2->next;
			}
			else {
				return false;
			}
		}
		return !(l1 != nullptr || l2 != nullptr);
	};

	// 生成链表
	auto createList = [](const vector<int> &nums) -> ListNode* {
		auto size{ nums.size() };
		if (size == 0) {
			return nullptr;
		}

		ListNode *head{ new ListNode(-1) };
		ListNode *node{ head };
		for (auto each : nums) {
			node->next = new ListNode(each);
			node = node->next;
		}

		node = head->next;
		delete head;
		return node;
	};

	// 删除链表
	auto deleteList = [](ListNode *head) {
		ListNode *tmp{ nullptr };
		while (head != nullptr) {
			tmp = head->next;
			delete head;
			head = tmp;
		}
	};

	auto func = [&](ListNode *l1, ListNode *l2, ListNode *ans, addTwoNumbers f) {
		cout << "输入：l1 = ";
		print(l1);
		cout << ", l2 = ";
		print(l2);
		cout << "\n输出：";
		auto res = (s.*f)(l1, l2);
		print(res);
		cout << "\n结果：";
		check(ans, res) ? std::cout << "正确\n\n" : std::cout << "错误\n\n";
		deleteList(l1);
		deleteList(l2);
		deleteList(ans);
		deleteList(res);
	};

	vector<int> nums11{ 2,4,3 }, nums21{ 5,6,4 }, ans1{ 7,0,8 };
	vector<int> nums12{ 0 }, nums22{ 0 }, ans2{ 0 };
	vector<int> nums13{ 9,9,9,9,9,9,9 }, nums23{ 9,9,9,9 }, ans3{ 8,9,9,9,0,0,0,1 };

	auto l1{ createList(nums11) };
	auto l2{ createList(nums21) };
	auto ans{ createList(ans1) };
	func(l1, l2, ans, &Solution::addTwoNumbers);


	l1 = createList(nums12);
	l2 = createList(nums22);
	ans = createList(ans2);
	func(l1, l2, ans, &Solution::addTwoNumbers);

	l1 = createList(nums13);
	l2 = createList(nums23);
	ans = createList(ans3);
	func(l1, l2, ans, &Solution::addTwoNumbers);
}