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

class power_of_two
{
private:
    /* data */
public:
    power_of_two(/* args */);
    ~power_of_two();
    bool isPowerOfTwo(int n)
    {
        return (n >= 1 && !(n & n - 1));
    }
};

power_of_two::power_of_two(/* args */)
{
}

power_of_two::~power_of_two()
{
}

// 解法3:位运算.
// 如果 n 是二的幂次方，那么 n 的二进制补码的有效位一定最高位为1且其它位均为0
// 而 n - 1 的二进制补码有效位的最高位较 n 低一位且所有位均为1.
// 因此若 n 为二的幂次方，则( n & n - 1 )一定为0;
// Mon,Feb1,2021
