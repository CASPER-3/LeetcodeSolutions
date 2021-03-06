/* 

给定一个整数，写一个函数来判断它是否是 4 的幂次方。如果是，返回 true ；否则，返回 false 。

整数 n 是 4 的幂次方需满足：存在整数 x 使得 n == 4x

 

示例 1：

输入：n = 16
输出：true
示例 2：

输入：n = 5
输出：false
示例 3：

输入：n = 1
输出：true
 

提示：

-231 <= n <= 231 - 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/power-of-four
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 */

#include <unordered_set>
using std::unordered_set;
class power_of_four
{
private:
    /* data */
public:
    power_of_four(/* args */);
    ~power_of_four();
    bool isPowerOfFour(int num)
    {
        if (num < 0 || num & (num - 1))
        { //check(is or not) a power of 2.
            return false;
        }
        return num & 0x55555555; //check 1 on odd bits
    }
};

power_of_four::power_of_four(/* args */)
{
}

power_of_four::~power_of_four()
{
}

// Wed,Feb3,2021