/* 

53. 最大子序和

difficulty: easy

给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

 

示例 1：

输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
输出：6
解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。
示例 2：

输入：nums = [1]
输出：1
示例 3：

输入：nums = [0]
输出：0
示例 4：

输入：nums = [-1]
输出：-1
示例 5：

输入：nums = [-100000]
输出：-100000
 

提示：

1 <= nums.length <= 3 * 104
-105 <= nums[i] <= 105
 

进阶：如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的 分治法 求解。

通过次数428,175提交次数801,293

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-subarray
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 */

#include <iostream>
#include <vector>
using std::cout;
using std::vector;

class maximum_subarray
{

public:
    int maxSubArray(vector<int> &nums)
    {
        vector<int> ans(nums.size(), 0);
        ans[0] = nums[0];

        int maxvalue = ans[0];
        for (int i = 1; i < ans.size(); ++i)
        {
            ans[i] = ans[i - 1] <= 0 ? nums[i] : nums[i] + ans[i - 1];
            maxvalue = ans[i] > maxvalue ? ans[i] : maxvalue;
        }
        return maxvalue;
    }
};


#pragma region DEBUG
#ifdef DEBUG
int main()
{
    vector<int> ivec{-2,1,-3,4,-1,2,1,-5,4};
    maximum_subarray ms;
    cout<<ms.maxSubArray(ivec)<<"\n";
}
#endif
#pragma endregion

/* 

[-2,1,-3,4,-1,2,1,-5,4]
 -2 1 -2 4 3  5 6 1  5

 */

// dp,我疯狂的dp.
// Wed,March3,2021
// 16:53:50:855:637503872308550779