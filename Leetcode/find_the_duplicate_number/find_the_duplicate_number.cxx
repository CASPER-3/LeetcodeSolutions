/* 

给定一个包含 n + 1 个整数的数组 nums ，其数字都在 1 到 n 之间（包括 1 和 n），可知至少存在一个重复的整数。

假设 nums 只有 一个重复的整数 ，找出 这个重复的数 。

 

示例 1：
              0 1 2 3  4           
输入：nums = [1,3,4,2,2]
输出：2
示例 2：

输入：nums = [3,1,3,4,2]
输出：3
示例 3：

输入：nums = [1,1]
输出：1
示例 4：

输入：nums = [1,1,2]
输出：1
 

提示：

2 <= n <= 3 * 104
nums.length == n + 1
1 <= nums[i] <= n
nums 中 只有一个整数 出现 两次或多次 ，其余整数均只出现 一次
 

进阶：

如何证明 nums 中至少存在一个重复的数字?
你可以在不修改数组 nums 的情况下解决这个问题吗？
你可以只用常量级 O(1) 的额外空间解决这个问题吗？
你可以设计一个时间复杂度小于 O(n2) 的解决方案吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-the-duplicate-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 */

#include <iostream>
#include <vector>
using std::cout;
using std::vector;

class find_the_duplicate_number
{
private:
    /* data */
public:
    find_the_duplicate_number(/* args */);
    ~find_the_duplicate_number();
    int findDuplicate(vector<int> &nums)
    {
        int n = nums.size();
        auto fast = nums.begin();
        auto slow = nums.begin();
        int size_of_range = 0;

        //试探环的大小
        do
        {
            fast = nums.begin() + *fast;
            fast = nums.begin() + *fast;
            slow = nums.begin() + *slow;
            ++size_of_range;
        } while (slow != fast);

        //寻找环的入口
        auto it = nums.begin();
        while (true)
        {
            auto temp = it;
            int count = 0;
            while (count < size_of_range)
            {
                temp = nums.begin() + *temp;
                ++count;
            }
            if (temp == it)
            {
                return temp - nums.begin();
            }
            it = nums.begin() + *it;
        }

        return 0;
    }
};

find_the_duplicate_number::find_the_duplicate_number(/* args */)
{
}

find_the_duplicate_number::~find_the_duplicate_number()
{
}

int main()
{
    //  0 1 2 3 4 5 6 7 8 9
    // [2,5,9,6,9,3,8,9,7,1]
    vector<int> ivec = {1,1,4,2};
    find_the_duplicate_number ftdn;
    cout << ftdn.findDuplicate(ivec);
    return 0;
}

/* 

            0 ---> 2 ---> 9 ---> 1 ---> 5 ---> 3 ---> 6 ---> 8 ---> 7 ---
                          /                                             /
                         /                                             /
                        /-------------------------------------------- /
                                                                    

 */

// Sat,Jan30,2021
// 观察题目的描述，比较容易的可以想到，可以把题目中的数组看作是一个链表，思路没什么问题，代码也通过了，只是性能好差