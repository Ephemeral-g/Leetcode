#include <iostream>
#include <vector>
#include <unordered_map>

using std::unordered_map;
using std::vector;
using std::cout;
using std::endl;

class Solution
{
public:
	// 方法一：
	vector<int> twoSum_1(vector<int> &nums, int target)
	{
		auto size = nums.size();
		for (decltype(size) i = 0; i < size; ++i) {
			for (decltype(size) j = i + 1; j < size; ++j) {
				if (nums.at(i) + nums.at(j) == target) {
					return { static_cast<int>(i), static_cast<int>(j) };
				}
			}
		}
		return {};
	}

	// 方法二：
	vector<int> twoSum_2(vector<int> &nums, int target)
	{
		unordered_map<int, size_t> res;
		auto size = nums.size();
		for (decltype(size) i = 0; i < size; ++i) {
			auto iter = res.find(target - nums.at(i));
			if (iter != res.end()) {
				return { static_cast<int>(iter->second), static_cast<int>(i) };
			}
			else {
				res.emplace(nums.at(i), i);
			}
		}
		return {};
	}

	// 方法三：
	vector<int> twoSum_3(vector<int> &nums, int target) 
	{
		decltype(nums.size()) left{ 0 }, right{ nums.size() - 1 };
		while (left != right) {
			int sum = nums.at(left) + nums.at(right);
			if (sum == target) {
				return { static_cast<int>(left), static_cast<int>(right) };
			}
			else if (sum < target) {
				++left;
			}
			else {
				--right;
			}
		}
		return {};
	}
};

// 类的成员函数
using twoSum = vector<int>(Solution::*)(vector<int> &, int);

int main()
{
	Solution s;

	auto print = [](vector<int> &nums) {
		cout << "[";
		auto size = nums.size();
		for (decltype(size) i = 0; i < size - 1; ++i) {
			cout << nums.at(i) << ", ";
		}
		cout << nums.at(size - 1) << "]";
	};

	auto func = [&](vector<int> &nums, int target, vector<int> &ans, twoSum f) {
		cout << "输入：nums = ";
		print(nums);
		cout << ", target = " << target << "\n输出：";
		auto res = (s.*f)(nums, target);
		print(res);
		cout << "\n结果：";
		std::equal(ans.begin(), ans.end(), res.begin(), res.end()) ? std::cout << "正确\n\n" : std::cout << "错误\n\n";
	};

	vector<int> nums1{ 2, 7, 11, 15 }, ans1{ 0, 1 };
	int target1{ 9 };
	vector<int> nums2{ 3, 2, 4 }, ans2{ 1,2 };
	int target2{ 6 };
	vector<int> nums3{ 3, 3 }, ans3{ 0, 1 };
	int target3{ 6 };

	cout << "方法一：\n";
	func(nums1, target1, ans1, &Solution::twoSum_1);
	func(nums2, target2, ans2, &Solution::twoSum_1);
	func(nums3, target3, ans3, &Solution::twoSum_1);

	cout << endl;
	cout << "方法二：\n";
	func(nums1, target1, ans1, &Solution::twoSum_2);
	func(nums2, target2, ans2, &Solution::twoSum_2);
	func(nums3, target3, ans3, &Solution::twoSum_2);

	cout << endl;
	cout << "方法三：\n";
	func(nums1, target1, ans1, &Solution::twoSum_3);
}