/* 

给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。

 

示例：

输入：nums = [-1,2,1,-4], target = 1
输出：2
解释：与 target 最接近的和是 2 (-1 + 2 + 1 = 2) 。
 

提示：

3 <= nums.length <= 10^3
-10^3 <= nums[i] <= 10^3
-10^4 <= target <= 10^4
通过次数188,042提交次数409,216

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/3sum-closest
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 */

#include <iostream>
#include <algorithm>
#include <vector>
using std::cout;
using std::sort;
using std::vector;

class _3sum_closest
{

public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        /* 
                 
                [-1,2,1,-4]
                [-4,-1,1,2]

         */
        sort(nums.begin(), nums.end());
        auto front_detector = nums.begin();
        auto back_detector = nums.begin();
        int ans = __INT32_MAX__ - 1e7;
        for (int i = 0; i < nums.size()-1; ++i)
        {
            front_detector = nums.begin() + i + 1;
            back_detector = nums.end()-1;
            while (front_detector < back_detector)
            {
                int temp_sum = nums[i] + *front_detector + *back_detector;
                if (temp_sum == target)
                {
                    return target;
                }
                ans = abs(ans - target) > abs(temp_sum - target) ? temp_sum : ans;
                front_detector = temp_sum > target ? front_detector : front_detector + 1;
                back_detector = temp_sum > target ? back_detector - 1 : back_detector;
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> ivec{-1, 2, 1, -4};
    _3sum_closest thriplecls;
    auto i = thriplecls.threeSumClosest(ivec, 1);
    cout << i << "\n";
}

//nature and nature's law lay hid in night,God say:'Let Newton be.',and all was light.
// Thu,Feb25,2021
// 13:31:56:542:637498567165426114