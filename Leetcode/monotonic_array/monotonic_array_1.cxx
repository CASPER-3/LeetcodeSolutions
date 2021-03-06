/* 

如果数组是单调递增或单调递减的，那么它是单调的。

如果对于所有 i <= j，A[i] <= A[j]，那么数组 A 是单调递增的。 如果对于所有 i <= j，A[i]> = A[j]，那么数组 A 是单调递减的。

当给定的数组 A 是单调数组时返回 true，否则返回 false。

 

示例 1：

输入：[1,2,2,3]
输出：true
示例 2：

输入：[6,5,4,4]
输出：true
示例 3：

输入：[1,3,2]
输出：false
示例 4：

输入：[1,2,4,5]
输出：true
示例 5：

输入：[1,1,1]
输出：true
 

提示：

1 <= A.length <= 50000
-100000 <= A[i] <= 100000
通过次数51,822提交次数88,446

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/monotonic-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 */

#include <vector>
using std::vector;

class monotonic_array
{

public:
    bool isMonotonic(vector<int> &A)
    {
        int left = 0;
        int right = A.size() - 1;
        bool inc = false;
        bool dec = false;
        while (left < right)
        {
            if (inc && dec)
            {
                return false;
            }
            inc = A[left + 1] > A[left] || A[right - 1] < A[right] ? true : inc;
            dec = A[left + 1] < A[left] || A[right - 1] > A[right] ? true : dec;
            ++left;
            --right;
        }
        return !(dec&&inc);
    }
};

// 好耶,好像这个题解会显示在执行用时提交分布图上.
// Mon,March1,2021
// 10:20:23:493:637501908234930810
