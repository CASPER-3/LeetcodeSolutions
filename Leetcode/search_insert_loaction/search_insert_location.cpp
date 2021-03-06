/*

给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

你可以假设数组中无重复元素。

示例 1:

输入: [1,3,5,6], 5
输出: 2
示例 2:

输入: [1,3,5,6], 2
输出: 1
示例 3:

输入: [1,3,5,6], 7
输出: 4
示例 4:

输入: [1,3,5,6], 0
输出: 0

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/search-insert-position
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/
#include <vector>
using std::vector;

class search_insert_location
{
private:
    /* data */
public:
    search_insert_location(/* args */);
    ~search_insert_location();
    int searchInsert(vector<int> &nums, int target)
    {
        if (nums.size() == 0)
        {
            return 0;
        }
        if (nums.size() == 1)
        {
            int location = (target <= nums[0]) ? 0 : 1;
            return location;
        }
        auto bg = nums.begin();
        auto ed = nums.end() - 1;
        if (*bg >= target)
        {
            return 0;
        }
        if (*ed <= target)
        {
            int location = (*ed == target) ? nums.size() - 1 : nums.size();
            return location;
        }
        while (bg < ed)
        {
            if ((*bg - target) * (*(bg + 1) - target) <= 0)
            {
                int location = (*bg == target) ? static_cast<int>(bg - nums.begin()) : static_cast<int>(bg + 1 - nums.begin());
                return location;
            }
            if ((*ed - target) * (*(ed - 1) - target) <= 0)
            {
                int location = (*(ed - 1) == target) ? static_cast<int>(ed - 1 - nums.begin()) : static_cast<int>(ed - nums.begin());
                return location;
            }
            ++bg;
            --ed;
        }
    }
};

search_insert_location::search_insert_location(/* args */)
{
}

search_insert_location::~search_insert_location()
{
}

//Thu,Jan28,2021
