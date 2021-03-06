/* 

给你一个数组 nums，对于其中每个元素 nums[i]，请你统计数组中比它小的所有数字的数目。

换而言之，对于每个 nums[i] 你必须计算出有效的 j 的数量，其中 j 满足 j != i 且 nums[j] < nums[i] 。

以数组形式返回答案。

 

示例 1：

输入：nums = [8,1,2,2,3]
输出：[4,0,1,1,3]
解释： 
对于 nums[0]=8 存在四个比它小的数字：（1，2，2 和 3）。 
对于 nums[1]=1 不存在比它小的数字。
对于 nums[2]=2 存在一个比它小的数字：（1）。 
对于 nums[3]=2 存在一个比它小的数字：（1）。 
对于 nums[4]=3 存在三个比它小的数字：（1，2 和 2）。
示例 2：

输入：nums = [6,5,4,8]
输出：[2,1,0,3]
示例 3：

输入：nums = [7,7,7,7]
输出：[0,0,0,0]
 

提示：

2 <= nums.length <= 500
0 <= nums[i] <= 100
通过次数73,821提交次数89,375

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/how-many-numbers-are-smaller-than-the-current-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 */

#include <iostream>
#include <vector>
using std::cout;
using std::vector;

class how_many_numbers_are_smaller_than_the_current_number
{

public:
    vector<int> smallerNumbersThanCurrent(vector<int> &nums)
    {

        /* 
        
        计数排序
        注意到数组元素的值域为 [0,100][0,100]，所以可以考虑建立一个频次数组 cntcnt ，
        cnt[i] 表示数字 i 出现的次数。那么对于数字 i 而言，
        小于它的数目就为 cnt[0...i−1] 的总和。

         */

        vector<int> cnt(101, 0);
        vector<int> ans;
        for (auto i : nums)
        {
            cnt[i]++;
        }
        for (int i = 1; i < 101; ++i)
        {
            cnt[i] += cnt[i - 1];
        }
        for (auto i : nums)
        {
            ans.push_back(i ? cnt[i - 1] : 0);
        }
        return ans;
    }
};

// 抄来的技术排序思想,时间复杂度O(n).
// Wed,Feb24,2021
// 13:14:44:966:637497692849663023
