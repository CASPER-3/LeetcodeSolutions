/* 

输入一个递增排序的数组和一个数字s，在数组中查找两个数，使得它们的和正好是s。如果有多对数字的和等于s，则输出任意一对即可。

 

示例 1：

输入：nums = [2,7,11,15], target = 9
输出：[2,7] 或者 [7,2]
示例 2：

输入：nums = [10,26,30,31,47,60], target = 40
输出：[10,30] 或者 [30,10]
 

限制：

1 <= nums.length <= 10^5
1 <= nums[i] <= 10^6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/he-wei-sde-liang-ge-shu-zi-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 */

#include <vector>
#include <unordered_set>
using std::unordered_multiset;
using std::vector;
class sumS
{
private:
    /* data */
public:
    sumS(/* args */);
    ~sumS();
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_multiset<int> dic(nums.begin(), nums.end());
        auto it = nums.begin();
        auto it2 = nums.end() - 1;
        while (it != it2)
        {
            int diff = target - *it;
            int diff2 = target - *it2;
            if (dic.count(diff) && diff != *it)
            {
                return {*it, diff};
            }
            if (dic.count(diff2) && diff2 != *it2)
            {
                return {*it2, diff2};
            }

            ++it;
            --it2;
        }
        return {};
    }
};

sumS::sumS(/* args */)
{
}

sumS::~sumS()
{
}

// Fri,Feb5,2021

// 3801.42
// 3794.52

//25*8=200
