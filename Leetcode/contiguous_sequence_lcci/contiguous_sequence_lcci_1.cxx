/* 

给定一个整数数组，找出总和最大的连续数列，并返回总和。

示例：

输入： [-2,1,-3,4,-1,2,1,-5,4]
输出： 6
解释： 连续子数组 [4,-1,2,1] 的和最大，为 6。
进阶：

如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。

通过次数24,146提交次数40,652

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/contiguous-sequence-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

该题与另外两题主题相同      https://leetcode-cn.com/problems/maximum-subarray/
                          https://leetcode-cn.com/problems/lian-xu-zi-shu-zu-de-zui-da-he-lcof/
  

 */

[[dynamic_programming]];

#include <vector>
using std::vector;

class contiguous_sequence_lcci
{

public:
    int maxSubArray(vector<int> &nums)
    {
        vector<int> ans(nums.size(), 0);
        ans[0] = nums[0];
        int maxval = ans[0];
        for (int i = 1; i < ans.size(); ++i)
        {
            ans[i] = ans[i - 1] <= 0 ? nums[i] : ans[i - 1] + nums[i];
            maxval = ans[i] > maxval ? ans[i] : maxval;
        }
        return maxval;
    }
};

// dp解法.
// 分治法还是不会.

/**
 * 内容相同于 @file ./maximum_subarray/maximum_subarray.cxx
 */

#ifdef LINK
#include "./maximum_subarray/maximum_subarray.cxx"
#endif
