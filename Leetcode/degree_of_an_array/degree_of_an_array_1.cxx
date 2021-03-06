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
#include <algorithm>
using std::sort;
using std::unordered_map;
using std::vector;

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
        for (int i = 0; i < nums.size(); ++i)
        {
            if (mp.count(nums[i]))
            {
                ++mp[nums[i]][0];
                mp[nums[i]][2] = i;
            }
            else
            {
                mp[nums[i]] = {1, i, i};
            }
        }
        
        auto it=mp.begin();
        int degree=it->second[0];
        int distance=(it->second[2]-it->second[1]);
        ++it;
        while(it!=mp.end())
        {
            if(it->second[0]>degree)
            {
                degree=it->second[0];
                distance=(it->second[2]-it->second[1]);
            }
            else if(it->second[0]==degree)
            {
                int tempdistance=it->second[2]-it->second[1];
                distance=tempdistance<distance?tempdistance:distance;
            }
            ++it;
        }
        return distance+1;
    }
};

degree_of_an_array::degree_of_an_array(/* args */)
{
}

degree_of_an_array::~degree_of_an_array()
{
}

// 还是参考了别人的代码吧,用unordered_map,思路应该是完全一样的,只是我不会他用的花里胡哨的C++17结构绑定,:(
// https://zh.cppreference.com/w/cpp/language/structured_binding
// Sat,Feb20,2021
