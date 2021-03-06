/* 

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
你能进一步完善解法吗？要求在C++或任何其他语言中不使用任何内置函数（如 C++ 中

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/counting-bits
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 */

#include <vector>
using std::vector;
class bitCount
{

public:
    vector<int> countBits(int num)
    {
        vector<int> ivec(num + 1, 0);
        int i = 1;
        while (i <= num)
        {
            ivec[i] = ivec[i & (i - 1)] + 1;
            ++i;
        }
        return ivec;
        ;
    }
};

/* 

    0       0000
    1       0001
    2       0010
    3       0011
    4       0100
    5       0101
    6       0110
    7       0111
    8       1000
    9       1001
    10      1010
    11      1011
    12      1100
    13      1101
    14      1110
    15      1111

 */
// Wed,Feb3,2021
