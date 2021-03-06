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
#include <algorithm>
#include <math.h>
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
        // if (!dividend)
        // {
        //     return 0;
        // }
        if (dividend == INT32_MIN || divisor == INT32_MIN)
        {
            if (divisor == -1)
            {
                return INT32_MAX;
            }
        }

        int op = (dividend > 0 && divisor > 0) ? 1 : (dividend < 0 && divisor < 0) ? 1
                                                                                   : 0;

        int idivid = dividend > 0 ? dividend : -dividend;
        int idivis = divisor > 0 ? divisor : -divisor;

        //using less.

        // if (idivid < idivis)
        // {
        //     return 0;
        // }
        // if (idivid == idivis)
        // {
        //     int result = op ? 1 : -1;
        // }
        // if (idivis == 1)
        // {
        //     return op ? idivid : -idivid;
        // }
        bitset<32> divid(idivid);
        bitset<32> divis(idivis);
        size_t result = 0;
        while (idivid >= idivis)
        {
            size_t pos1 = firstIndex(divid);
            size_t pos2 = firstIndex(divis);
            size_t diff = pos1 - pos2;
            // if ((idivis << diff) <= idivid)
            // {
            //     result += (1 << diff);
            //     idivid -= (idivis << (diff));
            //     divid = bitset<32>(idivid);
            // }
            // else
            // {

            //     idivid -= (idivis << (--diff));
            //     divid = bitset<32>(idivid);
            //     result += (1 << diff);
            // }
            diff = ((idivis << diff) <= idivid) ? diff : diff - 1;
            idivid -= (idivis << (diff));
            divid = bitset<32>(idivid);
            result += (1 << diff);

            /* code */
        }
        return op ? result : -result;
        // auto op_divid = divid[31];
        // auto op_divis = divis[31];

        // if (dividend == 0)
        // {
        //     return 0;
        // }
        // if (divisor == 1 || divisor == -1)
        // {
        //     long long result = divisor * dividend;
        //     if(result>0)
        //     {
        //         result = result > INT32_MAX ? INT32_MAX : result;
        //     }
        //     else
        //     {
        //         result = result < INT32_MIN ? INT32_MIN : result;
        //     }

        //     return result;

        // }
        // int op = (dividend > 0 && divisor > 0) ? 1 : (dividend < 0 && divisor < 0) ? 1
        //                                                                            : -1;
        // long long divid = (dividend > 0) ? dividend : -dividend;
        // long long divis = (divisor > 0) ? divisor : -divisor;
        // long long result = 0;

        // while (divid >= divis)
        // {
        //     divid -= divis;
        //     ++result;
        // }
        // if (op == 1)
        // {
        //     result = result > INT32_MAX ? INT32_MAX : result;
        // }
        // else
        // {
        //     result = result * -1;
        //     result = result < INT32_MIN ? INT32_MIN : result;
        // }

        // return result;
        // bitset<32> divid(dividend);
        // bitset<32> divis(divisor);
        // auto op_divid = divid[31];
        // auto op_divis = divis[31];
        // int op = (op_divid == op_divis) ? 1 : 0;
        // 0000 0000 0000 0000 0000 0000 0000 1010
        // 0000 0000 0000 0000 0000 0000 0000 0011
        // 0000 0000 0000 0000 0000 0000 0000 0111
        // 0000 0000 0000 0000 0000 0000 0000 0010 and
        // 0000 0000 0000 0000 0000 0000 0000 1011 or
        // 0000 0000 0000 0000 0000 0000 0000 1001 xor
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
    cout << dwi.divide(0, 3);
}

//Fri,Jan29,2021
//Thu,Jan28,2021


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