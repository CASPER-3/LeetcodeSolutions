/* 

给你一个数组 nums 。数组「动态和」的计算公式为：runningSum[i] = sum(nums[0]…nums[i]) 。

请返回 nums 的动态和。

 

示例 1：

输入：nums = [1,2,3,4]
输出：[1,3,6,10]
解释：动态和计算过程为 [1, 1+2, 1+2+3, 1+2+3+4] 。
示例 2：

输入：nums = [1,1,1,1,1]
输出：[1,2,3,4,5]
解释：动态和计算过程为 [1, 1+1, 1+1+1, 1+1+1+1, 1+1+1+1+1] 。
示例 3：

输入：nums = [3,1,2,10,1]
输出：[3,4,6,16,17]
 

提示：

1 <= nums.length <= 1000
-10^6 <= nums[i] <= 10^6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/running-sum-of-1d-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 */

#include <vector>
using std::vector;
class running_sum_of_1d_array
{
private:
    /* data */
public:
    running_sum_of_1d_array(/* args */);
    ~running_sum_of_1d_array();
    vector<int> runningSum(vector<int> &nums)
    {
        for(int i=1;i<nums.size();++i)
        {
            nums[i]+=nums[i-1];
        }
        return nums;
    }
};

running_sum_of_1d_array::running_sum_of_1d_array(/* args */)
{
}

running_sum_of_1d_array::~running_sum_of_1d_array()
{
}

// Wed,Feb24,2021
// 09:50:40:576:637497570405760957
