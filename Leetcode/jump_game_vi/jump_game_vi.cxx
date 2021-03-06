/* 

给你一个下标从 0 开始的整数数组 nums 和一个整数 k 。

一开始你在下标 0 处。每一步，你最多可以往前跳 k 步，但你不能跳出数组的边界。也就是说，你可以从下标 i 跳到 [i + 1， min(n - 1, i + k)] 包含 两个端点的任意位置。

你的目标是到达数组最后一个位置（下标为 n - 1 ），你的 得分 为经过的所有数字之和。

请你返回你能得到的 最大得分 。

 

示例 1：

输入：nums = [1,-1,-2,4,-7,3], k = 2
输出：7
解释：你可以选择子序列 [1,-1,4,3] （上面加粗的数字），和为 7 。
示例 2：

输入：nums = [10,-5,-2,4,0,3], k = 3
输出：17
解释：你可以选择子序列 [10,4,3] （上面加粗数字），和为 17 。
示例 3：

输入：nums = [1,-5,-20,4,-1,3,-6,-3], k = 2
输出：0
 


提示：

 1 <= nums.length, k <= 105
-104 <= nums[i] <= 104
通过次数4,184提交次数10,333

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/jump-game-vi
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 */

#include <vector>
using std::vector;

class jump_game_vi
{

public:
    int maxResult(vector<int> &nums, int k)
    {
        int sum = 0;
        int pos = 0;

        auto calc_next_pos = [=](int currtnypos) -> int {

        };
        while (pos <= nums.size())
        {
            sum += nums[pos];
        }
    }
};

// 这好像也是一道动态规划...这几天每日一题全是动态规划,连随机刷出的题也是动态规划,要去学一哈了.
// Wed,March3,2021