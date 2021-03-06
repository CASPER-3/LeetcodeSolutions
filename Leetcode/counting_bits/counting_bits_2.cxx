/* 

338. 比特位计数

difficulty: medium
给定一个非负整数 num。对于 0 ≤ i ≤ num 范围中的每个数字 i ，计算其二进制数中的 1 的数目并将它们作为数组返回。

示例 1:

输入: 2
输出: [0,1,1]
示例 2:

输入: 5
输出: [0,1,1,2,1,2]
进阶:

给出时间复杂度为O(n*sizeof(integer))的解答非常容易。但你可以在线性时间O(n)内用一趟扫描做到吗？
要求算法的空间复杂度为O(n)。
你能进一步完善解法吗？要求在C++或任何其他语言中不使用任何内置函数（如 C++ 中的 __builtin_popcount）来执行此操作。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/counting-bits
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 */

#include <vector>
using std::vector;
class counting_bits_2
{

public:
    vector<int> countBits(int num)
    {
        vector<int> ans(num + 1, 0);
        for (int i = 1; i <= num; ++i)
        {
            ans[i] = ans[i & i - 1] + 1;
        }
        return ans;
    }
};


/* 

    0       0000    0
    1       0001    1
    2       0010    1
    3       0011    2
    4       0100    1
    5       0101    2
    6       0110    2
    7       0111    3
    8       1000    1
    9       1001    2
    10      1010    2
    11      1011    3
    12      1100    2
    13      1101    3
    14      1110    3
    15      1111    4

 */

// 每日一题又刷到了,重新做一哈.不用std::bitset的话,这好像是一道动态规划题,好像也可以当找规律题来做...自己并没有想出来,参考了别人的天才解法.
// Wed,March3,2021
// 08:45:32:144:637503579321444119


/* 

按位与运算（\&&）的一个性质是：对于任意整数 xx，令 x=x \&(x-1)x=x&(x−1)，该运算将 xx 的二进制表示的最后一个 11 变成 00。因此，对 xx 重复该操作，直到 xx 变成 00，则操作次数即为 xx 的「一比特数」。

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/counting-bits/solution/bi-te-wei-ji-shu-by-leetcode-solution-0t1i/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

 */


