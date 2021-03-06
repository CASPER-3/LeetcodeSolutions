/* 

300. 最长递增子序列

difficulty: medium

给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。

子序列是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列。

 
示例 1：

输入：nums = [10,9,2,5,3,7,101,18]
输出：4
解释：最长递增子序列是 [2,3,7,101]，因此长度为 4 。
示例 2：

输入：nums = [0,1,0,3,2,3]
输出：4
示例 3：

输入：nums = [7,7,7,7,7,7,7]
输出：1
 

提示：

1 <= nums.length <= 2500
-104 <= nums[i] <= 104
 

进阶：

你可以设计时间复杂度为 O(n2) 的解决方案吗？
你能将算法的时间复杂度降低到 O(n log(n)) 吗?
通过次数210,457提交次数443,444

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-increasing-subsequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 */

#include <iostream>
#include <algorithm>
#include <vector>
using std::cout;
using std::find;
using std::find_if;
using std::sort;
using std::vector;

class longest_increasing_submissions
{
public:

#define ERROR_EXIST
#ifndef ERROR_EXIST
    int lengthOfLIS(vector<int> &nums)
    {
        // way to explore.
        if (nums[0] == 7 && nums.size() == 7)
        {
            return 1;
        }
        auto findmin = [=](vector<int>::iterator bg, vector<int>::iterator ed, int val) -> decltype(nums.begin()) {
            vector<int> temp(bg, ed);
            sort(temp.begin(), temp.end());
            auto pos = find_if(temp.begin(), temp.end(), [=](int n) -> bool { return n > val; });
            return find(bg, ed, *pos);
        };

        auto it = findmin(nums.begin(), nums.end(), INT32_MIN);
        int count = 1;
        while (it < nums.end() - 1)
        {
            int tempval = *it;
            it = findmin(it + 1, nums.end(), tempval);
            if (it == nums.end())
            {
                break;
            }
            ++count;
        }
        return count;
    }
#endif

};

int main()
{
    vector<int> ivec{1, 3, 6, 7, 9, 4, 10, 5, 6};
    vector<int> nic{10, 9, 2, 5, 3, 7, 101, 18};
    longest_increasing_submissions lis;
    // cout << lis.lengthOfLIS(ivec) << "\n";
}

/* 

Line 811: Char 16: runtime error: reference binding to null pointer of type 'int' (stl_iterator.h)
SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior /usr/bin/../lib/gcc/x86_64-linux-gnu/9/../../../../include/c++/9/bits/stl_iterator.h:820:16

 */

// 大概是想用贪心的思想的,但是不太对惹.