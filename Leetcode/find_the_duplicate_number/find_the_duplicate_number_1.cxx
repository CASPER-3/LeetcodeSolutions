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

public:
    find_the_duplicate_number();
    ~find_the_duplicate_number();
    int findDuplicate(vector<int> &nums)
    {

        auto fast = nums.begin();
        auto slow = nums.begin();
        
        //寻找快/慢指针的相遇位置
        do
        {
            fast = nums.begin() + *(nums.begin() + *fast);
            slow = nums.begin() + *slow;
        } while (slow != fast);

        //寻找环的入口
        auto it = nums.begin();
        while (it != slow)
        {
            it = nums.begin() + *it;
            slow = nums.begin() + *slow;
        }

        return (it - nums.begin());
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
    vector<int> ivec = {1, 1, 4, 2};
    find_the_duplicate_number ftdn;
    cout << ftdn.findDuplicate(ivec);
    return 0;
}

/* 
                                                                                                                                                                   
             ______x1______                                   _____x2_____                    
            |             |                                  |           |
            0 ---> 2 ---> 9 ---> 1 ---> 5 ---> 3 ---> 6 ---> 8 ---> 7 ---
                          /                                             /
                         /                                             /
                        /-------------------------------------------- /
                                                                    

 */


// 参考了一下别人的代码，优化了一下寻找环入口的算法.
// 不需要明确指出环的大小.
// 慢指针第一次遇到快指针的位置出发到环入口位置的距离 == (虚拟)链表起始位置到环入口位置的距离
//既 x1 == x2.

//reference code.
/* 

int findDuplicate(vector<int>& nums) {
    int res = 0;
    for (int fast = 0; res != fast || fast == 0;){
        res = nums[res];
        fast = nums[nums[fast]];
    }
    cout << res;
    for (int i = 0; res != i; i = nums[i]){
        res = nums[res];
    }
    return res;
}

 */


// Sat,Jan30,2021