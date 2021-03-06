/* 

34. 在排序数组中查找元素的第一个和最后一个位置
给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

如果数组中不存在目标值 target，返回 [-1, -1]。

进阶：

你可以设计并实现时间复杂度为 O(log n) 的算法解决此问题吗？
 

示例 1：

输入：nums = [5,7,7,8,8,10], target = 8
输出：[3,4]
示例 2：

输入：nums = [5,7,7,8,8,10], target = 6
输出：[-1,-1]
示例 3：

输入：nums = [], target = 0
输出：[-1,-1]
 

提示：

0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums 是一个非递减数组
-109 <= target <= 109
通过次数208,608提交次数494,021
find-first-and-last-position-of-element-in-sorted-array
 */

#include <vector>
using std::vector;
class st_ed_pos
{
private:
    /* data */
public:
    st_ed_pos(/* args */);
    ~st_ed_pos();
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] == target)
            {
                int count = 1;
                int lp = mid - 1;
                int rp = mid + 1;
                while (lp >= 0 && nums[lp] == target)
                {
                    ++count;
                    --lp;
                }
                while (rp < nums.size() && nums[rp] == target)
                {
                    ++count;
                    ++rp;
                }

                return {lp+1,rp-1};
            }
            left = nums[mid] > target ? left : mid + 1;
            right = nums[mid] > target ? mid - 1 : right;
        }
        return {-1,-1};
    }
};

st_ed_pos::st_ed_pos(/* args */)
{
}

st_ed_pos::~st_ed_pos()
{
}

// binary search,好耶.
// Thu,Feb18,2021
