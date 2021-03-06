/* 

给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 的那 两个 整数，并返回它们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。

你可以按任意顺序返回答案。

 

示例 1：

输入：nums = [2,7,11,15], target = 9
输出：[0,1]
解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
示例 2：

输入：nums = [3,2,4], target = 6
输出：[1,2]
示例 3：

输入：nums = [3,3], target = 6
输出：[0,1]
 

提示：

2 <= nums.length <= 103
-109 <= nums[i] <= 109
-109 <= target <= 109
只会存在一个有效答案
通过次数1,781,567提交次数3,543,488

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/two-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 */

#include <iostream>
#include <vector>
#include <algorithm>
using std::cout;
using std::sort;
using std::find;
using std::vector;

class two_sum
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {   
        [[un_correct]]
        vector<int> backup(nums);
        sort(nums.begin(), nums.end());
        auto back = nums.begin();
        auto front = nums.end() - 1;
        int sum = 0;
        while (back < front)
        {
            sum = *back + *front;
            if (sum == target)
            {
                return {static_cast<int>(find(backup.begin(),backup.end(),*back)-backup.begin()), static_cast<int>(find(backup.begin(),backup.end(),*front)-backup.begin())};
            }
            back = sum > target ? back : back + 1;
            front = sum > target ? front - 1 : front;
        }
        return {};
    }
};


// 梦开始的地方.leetcode第一题,想用新解法做一下不过好像思路不太对.
// Thu,Feb25,2021
// 15:48:24:117:637498649041177466

