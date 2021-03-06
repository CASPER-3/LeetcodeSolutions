/* 

给定 n 个整数，找出平均数最大且长度为 k 的连续子数组，并输出该最大平均数。

 

示例：

输入：[1,12,-5,-6,50,3], k = 4
输出：12.75
解释：最大平均数 (12-5-6+50)/4 = 51/4 = 12.75
 

提示：

1 <= k <= n <= 30,000。
所给数据范围 [-10,000，10,000]。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-average-subarray-i
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <windows.h>
using std::cout;
using std::endl;
using std::sort;
using std::vector;
class maximum_average_subarray_i
{
private:
    /* data */
public:
    maximum_average_subarray_i(/* args */);
    ~maximum_average_subarray_i();
    double findMaxAverage(vector<int> &nums, int k)
    {
        int front = 0;
        int back = k - 1;
        double tempSum = 0;
        double maxSum = 0;
        for (int temp = front; temp <= back; ++temp)
        {
            tempSum += nums[temp];
        }

        maxSum = tempSum;
       
        while (back != nums.size() - 1)
        {

            tempSum -= nums[front];
            ++front;
            ++back;
            tempSum += nums[back];
            maxSum = tempSum > maxSum ? tempSum : maxSum;
        }
        return maxSum / k;
    }
};

// 稍微优化了一下的版本.不需要使用额外的辅助vector,空间性能稍微好一些.
// Thu,Feb4,2021
/* 

Today is the 35th day of 2021

2021 has passed 9.41274733637747%

Fuck Life.

 */



