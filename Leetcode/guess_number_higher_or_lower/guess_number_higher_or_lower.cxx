/* 

猜数字游戏的规则如下：

每轮游戏，我都会从 1 到 n 随机选择一个数字。 请你猜选出的是哪个数字。
如果你猜错了，我会告诉你，你猜测的数字比我选出的数字是大了还是小了。
你可以通过调用一个预先定义好的接口 int guess(int num) 来获取猜测结果，返回值一共有 3 种可能的情况（-1，1 或 0）：

-1：我选出的数字比你猜的数字小 pick < num
1：我选出的数字比你猜的数字大 pick > num
0：我选出的数字和你猜的数字一样。恭喜！你猜对了！pick == num
返回我选出的数字。

 

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/guess-number-higher-or-lower
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 */

#include <iostream>
using std::cout;
using std::endl;
extern int guess(int n);

class guss_num
{
private:
    /* data */
public:
    guss_num(/* args */);
    ~guss_num();
    int guessNumber(int n)
    {
        int left = 1;
        int right = n;
        int mid = left + ((right - left) >> 1);
        while (guess(mid) != 0)
        {
            left = guess(mid) == 1 ? left : mid + 1;
            right = guess(mid) == 1 ? mid - 1 : right;
            mid = left + ((right - left) >> 1);
        }

        return mid;
    }
};

guss_num::guss_num(/* args */)
{
}

guss_num::~guss_num()
{
}
/*    l         l    m    r
      1,2,3,4,5,6,7,8,9,10 
      
      
*/

// 题目本身没什么，就二分查找，不过题目描述不太清楚，容易误解.
// Sun,Feb7,2021
