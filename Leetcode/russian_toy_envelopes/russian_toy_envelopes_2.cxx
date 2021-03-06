/* 
354. 俄罗斯套娃信封问题

difficulty: hard

给定一些标记了宽度和高度的信封，宽度和高度以整数对形式 (w, h) 出现。当另一个信封的宽度和高度都比这个信封大的时候，这个信封就可以放进另一个信封里，如同俄罗斯套娃一样。

请计算最多能有多少个信封能组成一组“俄罗斯套娃”信封（即可以把一个信封放到另一个信封里面）。

说明:
不允许旋转信封。

示例:

输入: envelopes = [[5,4],[6,4],[6,7],[2,3]]
输出: 3 
解释: 最多信封的个数为 3, 组合为: [2,3] => [5,4] => [6,7]。
通过次数26,682提交次数67,534

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/russian-doll-envelopes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 */

#define NEED_A_BETTER_SOLUTIONS

#include <iostream>
#include <algorithm>
#include <vector>
using std::cout;
using std::sort;
using std::vector;

class russian_toy_envelopes
{

public:
#ifndef ERROR_EXIST

    int maxEnvelopes(vector<vector<int>> &envelopes)
    {
        if (envelopes.empty())
        {
            return 0;
        }
        auto less = [](vector<int> envelop, vector<int> another_envelop) -> bool {
            return envelop[0] < another_envelop[0];
        };

        sort(envelopes.begin(), envelopes.end(), less);
        vector<int> dp(envelopes.size(), 1);
        for (int i = 1; i < dp.size(); ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (envelopes[j][1] < envelopes[i][1] && envelopes[j][0] < envelopes[i][0] && dp[j] + 1 > dp[i])
                {
                    dp[i] = dp[j] + 1;
                }
            }
        }

        sort(dp.begin(), dp.end());
        return *(dp.end() - 1);
    }
#endif
};

#pragma region DEBUG
#ifdef DEBUG
int main()
{
    vector<vector<int>> envelopes{{30, 50}, {12, 2}, {3, 4}, {12, 15}};
    vector<vector<int>> ath_envelopes{{2, 100}, {3, 200}, {4, 300}, {5, 500}, {5, 400}, {5, 250}, {6, 370}, {6, 360}, {7, 380}};
    vector<vector<int>> envelopes_3{{46, 89}, {50, 53}, {52, 68}, {72, 45}, {77, 81}};
    vector<vector<int>> envelopes_4{{8, 3}, {3, 20}, {15, 5}, {11, 2}, {19, 6}, {9, 18}, {1, 19}, {13, 3}, {14, 20}, {6, 7}};

    vector<vector<int>> envelopes_5{{4, 5}, {4, 6}, {6, 7}, {2, 3}, {1, 1}};

    russian_toy_envelopes rte;
    cout << rte.maxEnvelopes(envelopes_5) << "\n";

    for (auto env : envelopes_5)
    {
        cout << env[0] << "," << env[1] << " ";
    }
    cout << "\n";
}
#endif
#pragma endregion

// 解法思路很朴实,其实相当于是进阶版的最长递增子序列问题,只需要固定一维(排序)之后即转换为求另一维的最长连续子序列问题,dp计算另一维最长连续子序列即可.

/**
 *  @file ./longest_increasing_subsequence/longest_increasing_subsequence.cxx
 */

#define REFERENCE
#ifndef REFERENCE

#include "./longest_increasing_subsequence/longest_increasing_subsequence_1.cxx"

#endif

// dp,继续疯狂的dp,三月dp月.
// Thu,March4,2021
// 14:46:46:267:637504660062677264