/* 

给定一个非空且只包含非负数的整数数组 nums，数组的度的定义是指数组里任一元素出现频数的最大值。

你的任务是在 nums 中找到与 nums 拥有相同大小的度的最短连续子数组，返回其长度。

 

示例 1：

输入：[1, 2, 2, 3, 1]
输出：2
解释：
输入数组的度是2，因为元素1和2的出现频数最大，均为2.
连续子数组里面拥有相同度的有如下所示:
[1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
最短连续子数组[2, 2]的长度为2，所以返回2.
示例 2：

输入：[1,2,2,3,1,4,2]
输出：6
 

提示：

nums.length 在1到 50,000 区间范围内。
nums[i] 是一个在 0 到 49,999 范围内的整数。
通过次数34,053提交次数59,951

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/degree-of-an-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 */

#include <unordered_map>
#include <vector>
using std::vector;
using std::unordered_map;

class degree_of_an_array
{
private:
    /* data */
public:
    degree_of_an_array(/* args */);
    ~degree_of_an_array();
    int findShortestSubArray(vector<int> &nums)
    {
        unordered_map<int, vector<int>> mp;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (mp.count(nums[i]))
            {
                mp[nums[i]][0]++;
                mp[nums[i]][2] = i;
            }
            else
            {
                mp[nums[i]] = {1, i, i};
            }
        }
        int maxNum = 0, minLen = 0;
        for (auto &[_, vec] : mp)
        {
            if (maxNum < vec[0])
            {
                maxNum = vec[0];
                minLen = vec[2] - vec[1] + 1;
            }
            else if (maxNum == vec[0])
            {
                if (minLen > vec[2] - vec[1] + 1)
                {
                    minLen = vec[2] - vec[1] + 1;
                }
            }
        }
        return minLen;
    }
};

degree_of_an_array::degree_of_an_array(/* args */)
{
}

degree_of_an_array::~degree_of_an_array()
{
}

// 不会惹,上边的代码是offical solution,还用了C++17.
// Sat,Feb20,2021
