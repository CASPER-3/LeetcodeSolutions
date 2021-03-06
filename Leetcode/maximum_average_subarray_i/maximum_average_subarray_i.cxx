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

#include <vector>
#include <algorithm>
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
        auto front = nums.begin();
        auto back = nums.begin() + k - 1;
        vector<double> ans;
        double tempSum = 0;
        for (auto temp = front; temp <= back; ++temp)
        {
            tempSum += *temp;
        }
        ans.push_back(tempSum / k);
        while (back != nums.end() - 1)
        {
            tempSum -= *front;
            ++front;
            ++back;
            tempSum += *back;
            ans.push_back(tempSum / k);
        }
        sort(ans.begin(), ans.end());
        return *(--ans.end());
    }
};

maximum_average_subarray_i::maximum_average_subarray_i(/* args */)
{
}

maximum_average_subarray_i::~maximum_average_subarray_i()
{
}

// 真就滑动窗口月?.
// Thu,Feb4,2021
/* 

Today is the 35th day of 2021

2021 has passed 9.41274733637747%

Fuck Life.

 */
