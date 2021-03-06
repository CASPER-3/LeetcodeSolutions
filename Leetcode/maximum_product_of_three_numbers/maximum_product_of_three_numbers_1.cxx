/* 

给你一个整型数组 nums ，在数组中找出由三个数组成的最大乘积，并输出这个乘积。

 

示例 1：

输入：nums = [1,2,3]
输出：6
示例 2：

输入：nums = [1,2,3,4]
输出：24
示例 3：

输入：nums = [-1,-2,-3]
输出：-6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-product-of-three-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 */

#include <vector>
#include <algorithm>
using std::sort;
using std::vector;

class maximum_product_of_three_numbers
{
private:
    /* data */
public:
    maximum_product_of_three_numbers(/* args */);
    ~maximum_product_of_three_numbers();
    int maximumProduct(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        return nums[0] > 0 || nums.size() == 3 || nums[0] * nums[1] * nums[nums.size() - 1] < nums[nums.size() - 1] * nums[nums.size() - 2] * nums[nums.size() - 3] ? nums[nums.size() - 1] * nums[nums.size() - 2] * nums[nums.size() - 3] : nums[0] * nums[1] * nums[nums.size() - 1];
    }
};

maximum_product_of_three_numbers::maximum_product_of_three_numbers(/* args */)
{
}

maximum_product_of_three_numbers::~maximum_product_of_three_numbers()
{
}

// 排序之后最大乘积就两种情况：1、如果全是正数就是最后三个数相乘 2、如果有负数最大的乘机要么是最后三个数相乘，要么是两个最小的负数相乘再乘以最大的正数
// TUe,Feb2,2021

/* 

Today is the 33th day of 2021

2021 has passed 8.92312278031456%

Fuck Life.

 */