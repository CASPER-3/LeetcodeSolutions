/* 

给定一个整数，编写一个函数来判断它是否是 2 的幂次方。

示例 1:

输入: 1
输出: true
解释: 20 = 1
示例 2:

输入: 16
输出: true
解释: 24 = 16
示例 3:

输入: 218
输出: false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/power-of-two
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 */

#include <unordered_set>
using std::unordered_set;
class power_of_two
{
private:
    /* data */
public:
    power_of_two(/* args */);
    ~power_of_two();
    bool isPowerOfTwo(int n)
    {
        // if (n > 1073741824 || n < 1)
        // {
        //     return false;
        // }
        unordered_set<int> bin{1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912, 1073741824};
        return !(bin.find(n) == bin.end());
    }
};

power_of_two::power_of_two(/* args */)
{
}

power_of_two::~power_of_two()
{
}

// 解法1:哈希表.
// Mon,Feb1,2021
