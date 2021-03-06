/* 

实现 int sqrt(int x) 函数。

计算并返回 x 的平方根，其中 x 是非负整数。

由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。

示例 1:

输入: 4
输出: 2
示例 2:

输入: 8
输出: 2
说明: 8 的平方根是 2.82842..., 
     由于返回类型是整数，小数部分将被舍去。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sqrtx
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 */

#include <iostream>
using std::cout;
using std::endl;

class sqrtx
{
private:
public:
    sqrtx();
    ~sqrtx();
    int mySqrt(int x)
    {
        if (!x)
        {
            return 0;
        }
        //2147483647
        //sqrt(__INT32_MAX__) == 46,340.95000105199;
        if (x >= 2147302921 && x < 2147395600)
        {
            return 46339;
        }
        if (x >= 2147395600)
        {
            return 46340;
        }
        int left = 1;
        int right = x;
        while (left + 1 < right)
        {
            int mid = (left + ((right - left) >> 1));
            if (x / mid == mid)
            {
                return mid;
            }
            left = (x / mid > mid) ? mid : left;
            right = (x / mid < mid) ? mid : right;
        }
        return left;
    }
};

sqrtx::sqrtx(/* args */)
{
}

sqrtx::~sqrtx()
{
}

int main()
{
    sqrtx sx;
    cout << sx.mySqrt(5) << endl;
}

/* 

                l       r                   
        1   2   3   4   5   6   7   8   9   10

 */

// change mid * mid < x to x / mid < mid,the former may cause overflow.

// Mon,Feb1,2021
