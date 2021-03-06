/* 

给你一个长度为 n 的整数数组，请你判断在 最多 改变 1 个元素的情况下，该数组能否变成一个非递减数列。

我们是这样定义一个非递减数列的： 对于数组中所有的 i (0 <= i <= n-2)，总满足 nums[i] <= nums[i + 1]。

 

示例 1:

输入: nums = [4,2,3]
输出: true
解释: 你可以通过把第一个4变成1来使得它成为一个非递减数列。
示例 2:

输入: nums = [4,2,1]
输出: false
解释: 你不能在只改变一个元素的情况下将其变为非递减数列。
 

说明：

1 <= n <= 10 ^ 4
- 10 ^ 5 <= nums[i] <= 10 ^ 5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/non-decreasing-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 */

#include <iostream>
#include <vector>
using std::vector;
class non_decreasing_array
{
private:
    /* data */
public:
    non_decreasing_array(/* args */);
    ~non_decreasing_array();
    bool checkPossibility(vector<int> &nums)
    {
        if (nums.size() <= 2)
        {
            return true;
        }
        auto back = nums.begin();
        auto front = nums.begin() + 1;

        while (front < nums.end() - 1)
        {
            if (*back > *front)
            {
                goto part2;
            }
            ++front;
            ++back;
        }
        return true;
    part2:
        int ori_back = *back;
        int ori_front = *front;
        *back = *front;

        auto it1 = nums.begin();
        auto it2 = nums.begin() + 1;

        while (it2 != nums.end())
        {
            if (*it1 > *it2)
            {
                goto ed;
            }
            ++it1;
            ++it2;
        }
        return true;
    ed:
        *back = ori_back;
        *front = ori_back;
        it1 = nums.begin();
        it2 = nums.begin() + 1;
        while (it2 != nums.end())
        {
            if (*it1 > *it2)
            {
                return false;
            }
            ++it1;
            ++it2;
        }
        return true;
    }
};

non_decreasing_array::non_decreasing_array(/* args */)
{
}

non_decreasing_array::~non_decreasing_array()
{
}

int main()
{
    non_decreasing_array nda;
    vector<int> ivec{1,2,3,4};
    //5,7,1,8
    std::cout << nda.checkPossibility(ivec) << std::endl;
}

/*

9
8
7
6
5
4        /\
3       /  \  /
2           \/
1
0

 */

// 简单题...不过思路不太好找,代码也有些丑陋.
// Sun,Feb7,2021