/* 

474. 一和零

difficulty: medium

给你一个二进制字符串数组 strs 和两个整数 m 和 n 。

请你找出并返回 strs 的最大子集的大小，该子集中 最多 有 m 个 0 和 n 个 1 。

如果 x 的所有元素也是 y 的元素，集合 x 是集合 y 的 子集 。

 

示例 1：

输入：strs = ["10", "0001", "111001", "1", "0"], m = 5, n = 3
输出：4
解释：最多有 5 个 0 和 3 个 1 的最大子集是 {"10","0001","1","0"} ，因此答案是 4 。
其他满足题意但较小的子集包括 {"0001","1"} 和 {"10","1","0"} 。{"111001"} 不满足题意，因为它含 4 个 1 ，大于 n 的值 3 。
示例 2：

输入：strs = ["10", "0", "1"], m = 1, n = 1
输出：2
解释：最大的子集是 {"0", "1"} ，所以答案是 2 。
 

提示：

1 <= strs.length <= 600
1 <= strs[i].length <= 100
strs[i] 仅由 '0' 和 '1' 组成
1 <= m, n <= 100
通过次数31,519提交次数56,650

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ones-and-zeroes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 */

#include <iostream>
#include <vector>
#include <string>
#include <bitset>
#include <algorithm>

using std::bitset;
using std::cout;
using std::sort;
using std::string;
using std::vector;

// 清规戒律,没有意义.

#define DEBUG
#define ERROR_EXIST

class ones_and_zeros
{

public:
#ifndef ERROR_EXIST
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        vector<int> dp(strs.size(), 0);
        vector<vector<int>> rem(strs.size(), {m, n});
        // vector<vector<int>> recorder(strs.size(), {0, 0});
        bitset<32> temp(strs[0]);

        int temp_count_one = temp.count();
        int temp_count_zero = strs[0].size() - temp_count_one;
        // recorder[0][0] = temp_count_zero;
        // recorder[0][1] = temp_count_one;
        if (temp_count_zero <= m && temp_count_one <= n)
        {
            dp[0] = 1;
        }

        rem[0][0] = m - temp_count_zero;
        rem[0][1] = n - temp_count_one;
        for (int i = 1; i < strs.size(); ++i)
        {
            bitset<32> temp(strs[i]);

            int count_one = temp.count();
            int count_zero = strs[i].size() - count_one;
            rem[i][0] = m - count_zero;
            rem[i][1] = n - count_one;
            // recorder[i][0] = count_zero;
            // recorder[i][1] = count_one;

            if (count_zero <= m && count_one <= n)
            {
                dp[i] = 1;
            }
            for (int j = 0; j < i; ++j)
            {
                if (count_zero <= rem[j][0] && count_one <= rem[j][1] && dp[j] + 1 >= dp[i])
                {
                    if (dp[j] + 1 == dp[i])
                    {
                        if (rem[j][0] - count_zero >= rem[i][0] && rem[j][1] - count_one >= rem[i][1])
                        {
                        }
                        else
                        {
                            break;
                        }
                    }
                    dp[i] = dp[j] + 1;
                    rem[i][0] = rem[j][0] - count_zero;
                    rem[i][1] = rem[j][1] - count_one;
                }
                // else if (count_zero + recorder[j][0] < m && count_one + recorder[j][1] < n && 2 > dp[i])
                // {
                //     dp[i] = 2;
                //     rem[i][0] = m - count_zero - recorder[j][0];
                //     rem[i][1] = n - count_one - recorder[j][1];
                // }
            }
        }

        sort(dp.begin(), dp.end());
        return *(dp.end() - 1);
    }
    #endif

};



#ifdef DEBUG
int main()
{
    /* 
    ["10","0001","111001","1","0"]
3
4
     */
    vector<string> strs{"10", "0001", "111001", "1", "0"};
    ones_and_zeros oaz;
    // cout << oaz.findMaxForm(strs, 3, 4) << "\n";
}

#endif

/* 
    m=5,n=3
        "10", "0001", "111001", "1", "0"
    dp    1       2         0    1    1
    rem   4,2    1,1        0    

    m=9,n=2
                "001", "110","0000","0000"
    dp            1     1       
    rem          7,1    8,0


    "10","0001","111001","1","0"
dp   1     1     1      
rem 2,3    0,3  1,0
m=3
n=4


 */

// 尝试着修改了半天,发觉不太对,这大概是一道背包dp题,我还不会做.