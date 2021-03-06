/* 

中位数是有序序列最中间的那个数。如果序列的大小是偶数，则没有最中间的数；此时中位数是最中间的两个数的平均数。

例如：

[2,3,4]，中位数是 3
[2,3]，中位数是 (2 + 3) / 2 = 2.5
给你一个数组 nums，有一个大小为 k 的窗口从最左端滑动到最右端。窗口中有 k 个数，每次窗口向右移动 1 位。你的任务是找出每次窗口移动后得到的新窗口中元素的中位数，并输出由它们组成的数组。

 

示例：

给出 nums = [1,3,-1,-3,5,3,6,7]，以及 k = 3。

窗口位置                      中位数
---------------               -----
[1  3  -1] -3  5  3  6  7       1
 1 [3  -1  -3] 5  3  6  7      -1
 1  3 [-1  -3  5] 3  6  7      -1
 1  3  -1 [-3  5  3] 6  7       3
 1  3  -1  -3 [5  3  6] 7       5
 1  3  -1  -3  5 [3  6  7]      6
 因此，返回该滑动窗口的中位数数组 [1,-1,-1,3,5,6]。

 

提示：

你可以假设 k 始终有效，即：k 始终小于输入的非空数组的元素个数。
与真实值误差在 10 ^ -5 以内的答案将被视作正确答案

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sliding-window-median
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <algorithm>
using std::cout;
using std::endl;
using std::find;
using std::sort;
using std::vector;

class sliding_window_medium
{
private:
    /* data */
public:
    sliding_window_medium(/* args */);
    ~sliding_window_medium();
    vector<double> medianSlidingWindow(vector<int> &nums, int k)
    {
        vector<int>::iterator front = nums.begin();
        vector<int>::iterator back = nums.begin() + k - 1;
        vector<double> result;
        vector<double> temp(front, back + 1);
        sort(temp.begin(), temp.end());

        while (back != nums.end() - 1)
        {

            int pivot = k / 2;
            result.push_back(k % 2 == 0 ? (temp[pivot - 1] + temp[pivot]) / 2 : temp[pivot]);
            temp.erase(find(temp.begin(), temp.end(), *front));
            ++back;
            ++front;
            int sp = 0;
            int ep = temp.size() - 1;
            // TODO 二分查找法

            temp.insert(temp.begin() + sp + 1, *back);
        }

        int pivot = k / 2;
        result.push_back(k % 2 == 0 ? (temp[pivot - 1] + temp[pivot]) / 2 : temp[pivot]);
        temp.erase(find(temp.begin(), temp.end(), *front));
        //之所以写成这种有些傻x的写法是因为线上环境开启了谷歌的内存错误探查器(sanitizers)，如果迭代器指向容器的尾后位置会报错，就很迷惑.
        //https://github.com/google/sanitizers/wiki/ThreadSanitizerAlgorithm

        return result;
    }
};

sliding_window_medium::sliding_window_medium(/* args */)
{
}

sliding_window_medium::~sliding_window_medium()
{
}

int main()
{
    vector<int> ivec{1, 3, -1, -3, 5, 3, 6, 7};
    sliding_window_medium swm;
    vector<double> rs = swm.medianSlidingWindow(ivec, 3);
    for (auto i : rs)
    {
        cout << i << " ";
    }
}

// 竟然用比较朴素(笨)的方法直接做出来了,虽然性能很差,自己做出的第一道困难题.
// sp                ep
// 0 1 2 3 4 5 6 7 8 9
// Wed,Feb3,2021
