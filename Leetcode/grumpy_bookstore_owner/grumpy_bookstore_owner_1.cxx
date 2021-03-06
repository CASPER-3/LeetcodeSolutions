/* 

/* 

今天，书店老板有一家店打算试营业 customers.length 分钟。每分钟都有一些顾客（customers[i]）会进入书店，所有这些顾客都会在那一分钟结束后离开。

在某些时候，书店老板会生气。 如果书店老板在第 i 分钟生气，那么 grumpy[i] = 1，否则 grumpy[i] = 0。 当书店老板生气时，那一分钟的顾客就会不满意，不生气则他们是满意的。

书店老板知道一个秘密技巧，能抑制自己的情绪，可以让自己连续 X 分钟不生气，但却只能使用一次。

请你返回这一天营业下来，最多有多少客户能够感到满意的数量。
 

示例：

输入：customers = [1,0,1,2,1,1,7,5], grumpy = [0,1,0,1,0,1,0,1], X = 3
输出：16
解释：
书店老板在最后 3 分钟保持冷静。
感到满意的最大客户数量 = 1 + 1 + 1 + 1 + 7 + 5 = 16.
 

提示：

1 <= X <= customers.length == grumpy.length <= 20000
0 <= customers[i] <= 1000
0 <= grumpy[i] <= 1
通过次数11,671提交次数21,365

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/grumpy-bookstore-owner
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 */

#include <vector>
#include <iostream>
using std::cout;
using std::vector;

class grumpy_bookstore_owner
{
private:
    /* data */
public:
    grumpy_bookstore_owner(/* args */);
    ~grumpy_bookstore_owner();
    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int X)
    {
        int back = 0;
        int front = X - 1;
        int maxSat = 0;
        int maxPos = 0;
        int tempSat = 0;
        int temp = back;

        while (temp <= front)
        {
            maxSat += grumpy[temp] ? customers[temp] : 0;
            ++temp;
        }
        tempSat = maxSat;
        while (front < customers.size() - 1)
        {
            tempSat -= grumpy[back] ? customers[back] : 0;
            ++back;
            ++front;
            tempSat += grumpy[front] ? customers[front] : 0;
            maxPos = tempSat > maxSat ? back : maxPos;
            maxSat = tempSat > maxSat ? tempSat : maxSat;
        }

        for (int it = maxPos; it < maxPos + X; ++it)
        {
            grumpy[it] = 0;
        }

        int ans = 0;
        for (int i = 0; i < customers.size(); ++i)
        {
            ans += !grumpy[i] ? customers[i] : 0;
        }
        return ans;
    }
};

grumpy_bookstore_owner::grumpy_bookstore_owner(/* args */)
{
}

grumpy_bookstore_owner::~grumpy_bookstore_owner()
{
}

int main()
{
    grumpy_bookstore_owner gbo;
    vector<int> customers{9, 10, 4, 5};
    vector<int> grumpy{1, 0, 1, 1};
    cout << gbo.maxSatisfied(customers, grumpy, 1);
}

// 修改了一下,去掉了计算窗口内值的和的二重循环,时间竟然从1k+ms降到了几十ms.
// Tue,Feb23,2021
// 09:54:02:66:637496708420662791
