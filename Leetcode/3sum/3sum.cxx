/* 

给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有和为 0 且不重复的三元组。

注意：答案中不可以包含重复的三元组。

 

示例 1：

输入：nums = [-1,0,1,2,-1,-4]
输出：[[-1,-1,2],[-1,0,1]]
示例 2：

输入：nums = []
输出：[]
示例 3：

输入：nums = [0]
输出：[]
 

提示：

0 <= nums.length <= 3000
-105 <= nums[i] <= 105

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/3sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 */

#include <iostream>
#include <algorithm>
#include <vector>
using std::cout;
using std::sort;
using std::unique_copy;
using std::vector;

class _3sum
{

public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        // -1   0   1   2   -1  -4
        // -4   -1 -1   0   1   2
        if (nums.size() < 3)
        {
            return {};
        }
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        auto front_detector = nums.begin();
        auto back_detector = nums.begin();
        for (auto it = nums.begin(); it != nums.end() - 1 && *it <= 0; ++it)
        {
            if (it > nums.begin() && *it == *(it - 1))
            {
                continue;
            }
            it = it > nums.begin() && *it == *(it - 1) ? it + 1 : it;
            front_detector = it + 1;
            back_detector = nums.end() - 1;
            while (front_detector < back_detector)
            {
                int temp_sum = *it + *front_detector + *back_detector;
                if (!temp_sum)
                {
                    ans.push_back({*it, *front_detector, *back_detector});
                    ++front_detector;
                    continue;
                }
                front_detector = temp_sum > 0 ? front_detector : front_detector + 1;
                back_detector = temp_sum > 0 ? back_detector - 1 : back_detector;
            }
        }
        vector<vector<int>> uniqueans;
        unique_copy(ans.begin(), ans.end(), std::back_inserter(uniqueans));
        return uniqueans;
        // return ans;
    }
};

int main()
{
    // -2,0,1,1,2
    vector<int> ivec{-1, 0, 1, 2, -1, -4};
    _3sum ths;
    for (auto vec : ths.threeSum(ivec))
    {
        for (auto i : vec)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
}

/* 
[-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6]
输出：
[[-4,-2,6],[-4,0,4],[-4,1,3],[-4,2,2],[-2,-2,4],[-2,0,2],[-2,-2,4],[-2,0,2]]
预期结果：
[[-4,-2,6],[-4,0,4],[-4,1,3],[-4,2,2],[-2,-2,4],[-2,0,2]]

 */

/**
 * 解法思路类似于 @file 3_sum_closet.cxx
 * 但是这个题去重很烦,跳转it和标准库的 unqiue_copy 都被用于去重
 * 跳转it不能去除输入均是0那种特殊情况产生的重复但是可以去除普通的重复
 * unqiue_copy 不能去除普通的重复但是可以去除输入均为0特殊情况的重复...
 * 拥有糟糕的空间性能.
 */

// Thu,Feb25,2021
//  14:54:54:912:637498616949128571

