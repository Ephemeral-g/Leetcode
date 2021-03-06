
class Solution {
public:
	int hammingDistance(int x, int y) {
		int tmp = x ^ y, result = 0;
		while (tmp) {
			if (tmp & 1) {
				++result;
			}
			tmp = tmp >> 1;
		}
		return result;
	}
	
	int hammingDistance(int x, int y) {
		int tmp = x ^ y, result = 0;
		while (tmp) {
			++result;
			tmp = tmp & (tmp - 1);
		}
		return result;
	}
};