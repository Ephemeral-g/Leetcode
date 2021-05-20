#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>

using std::unordered_map;
using std::string;
using std::cout;
using std::endl;
using std::max;

class Solution 
{
public:
	int lengthOfLongestSubstring_1(const string &s)
	{
		int size{ 0 }, start{ 0 };  // 滑动窗口的大小和起始位置
		int res{ 0 };  // 结果
		for (int i = 0, len = s.size(); i < len; ++i) {
			for (int j = start; j < start + size; ++j) {
				if (s[i] == s[j]) {
					// 当出现相同字符时，重新计算记录窗口大小
					size = size - (j - start + 1);
					start = j + 1;  // 重新计算窗口的起始位置
					break;
				}
			}
			++size;  // 将当前字符加入窗口中
			res = max(res, size);
		}
		return res;
	}

	int lengthOfLongestSubstring_2(const string &s)
	{
		int size{ 0 }, start{ 0 };  // 滑动窗口的大小和起始位置
		int res{ 0 };  // 结果
		unordered_map<char, size_t> hash;
		for (decltype(s.size()) i = 0, len = s.size(); i < len; ++i) {
			auto iter = hash.find(s[i]);
			if (iter != hash.end() && iter->second >= start) {
				start = iter->second + 1;
				size = i - start;
			}
			hash[s[i]] = i;
			++size;
			res = max(size, res);
		}
		return res;
	}
};

// 类的成员函数
using lengthOfLongestSubstring = int (Solution::*)(const string &);

int main()
{
	Solution s;
	auto func = [&](const string &str, int ans, lengthOfLongestSubstring f) {
		cout << R"(输入：s = ")" << str << R"(")" << std::endl;
		cout << "输出：";
		auto res = (s.*f)(str);
		cout << res;
		cout << "\n结果：";
		ans == res ? std::cout << "正确\n\n" : std::cout << "错误\n\n";
	};

	string str1{ "abcabcbb" }, str2{ "bbbbb" }, str3{ "pwwkew" }, str4{ "abba" }, str5{ "awefxciuhnkr" };
	int ans1{ 3 }, ans2{ 1 }, ans3{ 3 }, ans4{ 2 }, ans5{ 12 };

	cout << "方法一：\n";
	func(str1, ans1, &Solution::lengthOfLongestSubstring_1);
	func(str2, ans2, &Solution::lengthOfLongestSubstring_1);
	func(str3, ans3, &Solution::lengthOfLongestSubstring_1);
	func(str4, ans4, &Solution::lengthOfLongestSubstring_1);
	func(str5, ans5, &Solution::lengthOfLongestSubstring_1);

	cout << "\n方法二：\n";
	func(str1, ans1, &Solution::lengthOfLongestSubstring_2);
	func(str2, ans2, &Solution::lengthOfLongestSubstring_2);
	func(str3, ans3, &Solution::lengthOfLongestSubstring_2);
	func(str4, ans4, &Solution::lengthOfLongestSubstring_2);
	func(str5, ans5, &Solution::lengthOfLongestSubstring_2);
}