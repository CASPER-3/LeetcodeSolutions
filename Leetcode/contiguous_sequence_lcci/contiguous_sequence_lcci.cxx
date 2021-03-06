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

[[divide_and_conquer]];

#include <vector>
using std::vector;

class contiguous_sequence_lcci
{

public:
    struct status
    {
        int lsum = 0;
        int rsum = 0;
        int msum = 0;
        int isum = 0;
        status(int rlsum, int rrsum, int rmsum, int risum) : lsum(rlsum), rsum(rrsum), msum(rmsum), isum(risum) {}
    };

    status pushup(status l, status r)
    {
        int isum = l.isum + r.isum;
        int lsum = std::max(l.lsum, l.isum + r.lsum);
        int rsum = std::max(r.rsum, r.isum + l.rsum);
        int msum = std::max(std::max(l.msum, r.msum), l.rsum + r.lsum);
        return status(lsum, rsum, msum, isum);
    }

    status get(vector<int> &a,int l,int r)
    {
        if(l==r)
        {
            return status(a[l],a[l],a[l],a[l]);
        }
        int m=(l+r)>>1;
        status lsub=get(a,l,m);
        status rsub=get(a,m+1,r);
        return pushup(lsub,rsub);
    }

    int maxSubArray(vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            return nums[0];
        }

        auto left = nums.begin();
        auto right = nums.end() - 1;
        auto mid = left + ((right - left) >> 1);

        vector<int> l_temp(left, mid + 1);
        vector<int> r_temp(mid + 1, right + 1);
        int l_val = maxSubArray(l_temp);
        int r_val = maxSubArray(r_temp);

        return get(nums,0,nums.size()-1).msum;
    }
};

// 不会...