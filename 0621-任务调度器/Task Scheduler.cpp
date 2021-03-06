#include <vector>
#include <unordered_map>
#include <algorithm>
using std::vector;
using std::unordered_map;
using std::max;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if (n == 0) {
            return tasks.size();
        }
        unordered_map<char, int> task_map;
        size_t max_task=0, max_count=0;  // 执行次数最多的任务, 执行次数最多的任务有多少个
        for (auto task : tasks) {
            ++task_map[task];
            if (task_map[task] > max_task) {
                max_task = task_map[task];
                max_count = 0;
            }
            else if (task_map[task] == max_task) {
                ++max_count;
            }
        }

        // size_t max_count=0;  // 执行次数最多的任务有多少个
        // for (auto task : task_map) {
        //     if (task.second == max_task) {
        //         ++max_count;
        //     }
        // }
        return max((max_task-1) * (n+1) + max_count, tasks.size());
    }
};