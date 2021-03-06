/* 

29两数相除

给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。

返回被除数 dividend 除以除数 divisor 得到的商。

整数除法的结果应当截去（truncate）其小数部分，例如：truncate(8.345) = 8 以及 truncate(-2.7335) = -2

 

示例 1:

输入: dividend = 10, divisor = 3
输出: 3
解释: 10/3 = truncate(3.33333..) = truncate(3) = 3
示例 2:

输入: dividend = 7, divisor = -3
输出: -2
解释: 7/-3 = truncate(-2.33333..) = -2
 

提示：

被除数和除数均为 32 位有符号整数。
除数不为 0。
假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−2^31,  2^31 − 1]。本题中，如果除法结果溢出，则返回 2^31 − 1。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/divide-two-integers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 */

#include <bitset>
#include <iostream>
using std::bitset;
using std::cout;
using std::endl;

class divide_two_integers
{
private:
    /* data */
public:
    divide_two_integers(/* args */);
    ~divide_two_integers();
    int divide(int dividend, int divisor)
    {

        // int op = (dividend > 0 && divisor > 0) ? 1 : (dividend < 0 && divisor < 0) ? 1
        //                                                                            : 0;

        // int idivid = dividend > 0 ? dividend : -dividend;
        // int idivis = divisor > 0 ? divisor : -divisor;
        if (dividend > 0 && divisor == INT32_MIN)
        {
            return 0;
        }
        bitset<32> divid(dividend);
        bitset<32> divis(divisor);

        int op = (divid[31] == divis[31]) ? 1 : 0;
        int divid_carry = divid[31] ? 1 : 0;
        int divis_carry = divis[31] ? 1 : 0;
        int sp_carry = (dividend == INT32_MIN && (divisor == 1 || divisor == 2)) ? 1 : 0;

        divid = divid[31] ? divid.flip() : divid;
        divis = divis[31] ? divis.flip() : divis;

        int idivid = (divid_carry && (divid.to_ulong() != INT32_MAX)) ? divid.to_ulong() + 1 : divid.to_ulong();
        int idivis = (divis_carry && (divis.to_ulong() != INT32_MAX)) ? divis.to_ulong() + 1 : divis.to_ulong();

        divid = bitset<32>(idivid);
        divis = bitset<32>(idivis);

        size_t result = 0;
        while (idivid >= idivis)
        {
            size_t pos1 = firstIndex(divid);
            size_t pos2 = firstIndex(divis);
            size_t diff = pos1 - pos2;
            diff = ((idivis << diff) <= idivid) ? diff : diff - 1;
            idivid -= (idivis << (diff));
            divid = bitset<32>(idivid);
            result += (1 << diff);
        }
        return op ? result : -result - sp_carry;
    }

    size_t firstIndex(bitset<32> bs)
    {
        if (bs.none())
        {
            return -1;
        }
        size_t idx = 31;
        while (idx > 0 && !bs.test(idx))
        {
            --idx;
        }

        return idx;
    }
};

divide_two_integers::divide_two_integers(/* args */)
{
}

divide_two_integers::~divide_two_integers()
{
}

int main()
{
    divide_two_integers dwi;
    cout << dwi.divide(-2147483648, 2);
    /*

         2147483647
        -2147483648

     */
}

//Fri,Jan29,2021
/* 

//dividend = divisor*2^2 + divisor*2^1 + divisor*2^0
//ans = 2^2 + 2^1 + 2^0
int divide(int dividend, int divisor) {
    long ans = 0, up = std::fabs(dividend), down = std::fabs(divisor);
    while(up >= down){
        long count = 1, base = down;
        while(up > (base << 1)){
            count <<= 1;
            base <<= 1;
        }
        ans += count;
        up -= base;
    }
    ans = ((dividend < 0)^(divisor < 0)) ? -ans : ans;
    return (ans > INT_MAX || ans < INT_MIN) ? INT_MAX : ans;
}

 */