/* 

统计一个数字在排序数组中出现的次数。

 

示例 1:

输入: nums = [5,7,7,8,8,10], target = 8
输出: 2
示例 2:

输入: nums = [5,7,7,8,8,10], target = 6
输出: 0
 

限制：

0 <= 数组长度 <= 50000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/zai-pai-xu-shu-zu-zhong-cha-zhao-shu-zi-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 */

#include <iostream>
#include <vector>
#include <algorithm>
using std::cout;
using std::endl;
using std::vector;
using std::lower_bound;
using std::upper_bound;

class search
{
private:
    /* data */
public:
    search(/* args */);
    ~search();
    int searchRange(vector<int> &nums, int target)
    {
        auto it1 = lower_bound(nums.begin(),nums.end(),target);
        auto it2 = upper_bound(it1,nums.end(),target);
        return it2 - it1;
    }
};

search::search(/* args */)
{
}

search::~search()
{
}

int main()
{
    search sr;
    vector<int> ivec{1};
    cout << sr.searchRange(ivec, 1) << endl;
}

// 抄来的看不太懂，这就是标准库的力量吗.jpg
// Thu,Feb18,2021