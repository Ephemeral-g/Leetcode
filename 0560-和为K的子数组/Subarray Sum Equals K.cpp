
class Solution {
public:
	// 方法一
	int subarraySum(vector<int>& nums, int k) {
		size_t size = nums.size();
		size_t count = 0;
		for (size_t i = 0; i < size; ++i) {
			int sum = 0;
			for (size_t j = i; j < size; ++j) {
				sum += nums[j];
				if (sum == k) {
					++count;
				}
			}
		}
		return count;
	}
	// 方法二
	int subarraySum(vector<int>& nums, int k) {
		size_t size = nums.size();
		vector<int> preSum(size, 0);
		for (int i = 0; i < size; ++i) {
			preSum[i + 1] = preSum[i] + nums[i];  // 计算前缀
		}
		size_t count = 0;
		for (size_t i = 0; i < size; ++i) {
			for (size_t j = i; j < size; ++j) {
				if (preSum[j + 1] - preSum[i] == k) {
					count++;
				}
			}
		}
		return count;
	}
	// 方法三
	int subarraySum(vector<int>& nums, int k) {
		unordered_map<int, int> preSum;
		preSum[0] = 1;
		int pre = 0;
		size_t count = 0;
		for (auto &each : nums) {
			pre += each;
			if (preSum.find(pre - k) != preSum.end()) {
				count += preSum[pre - k];
			}
			preSum[pre]++;
		}
		return count;
	}
};