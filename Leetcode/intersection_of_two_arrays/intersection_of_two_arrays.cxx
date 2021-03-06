/* 

给定两个数组，编写一个函数来计算它们的交集。

 

示例 1：

输入：nums1 = [1,2,2,1], nums2 = [2,2]
输出：[2]
示例 2：

输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出：[9,4]
 

说明：

输出结果中的每个元素一定是唯一的。
我们可以不考虑输出结果的顺序。
通过次数157,693提交次数214,453

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/intersection-of-two-arrays
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 */

#include <iostream>
#include <vector>
#include <unordered_set>
using std::cout;
using std::unordered_set;
using std::vector;
class intersection_of_two_arrays
{
private:
    /* data */
public:
    intersection_of_two_arrays(/* args */);
    ~intersection_of_two_arrays();
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> ans;
        unordered_set<int> s1(nums1.begin(), nums1.end());
        unordered_set<int> s2(nums2.begin(), nums2.end());
        for (auto i : s1)
        {
            if (s2.count(i))
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

intersection_of_two_arrays::intersection_of_two_arrays(/* args */)
{
}

intersection_of_two_arrays::~intersection_of_two_arrays()
{
}

int main()
{
    vector<int> ivec1{1, 2, 2, 1};
    vector<int> ivec2{2, 2};
    intersection_of_two_arrays iota;
    auto ans=iota.intersection(ivec1,ivec2);
    for(auto i:ans)
    {
        cout<<i<<" ";
    }
    return 0;
}

// Mon,Feb22,2021
