/* 

爱丽丝和鲍勃一起玩游戏，他们轮流行动。爱丽丝先手开局。

最初，黑板上有一个数字 N 。在每个玩家的回合，玩家需要执行以下操作：

选出任一 x，满足 0 < x < N 且 N % x == 0 。
用 N - x 替换黑板上的数字 N 。
如果玩家无法执行这些操作，就会输掉游戏。

只有在爱丽丝在游戏中取得胜利时才返回 True，否则返回 False。假设两个玩家都以最佳状态参与游戏。

 

示例 1：

输入：2
输出：true
解释：爱丽丝选择 1，鲍勃无法进行操作。
示例 2：

输入：3
输出：false
解释：爱丽丝选择 1，鲍勃也选择 1，然后爱丽丝无法进行操作。
 

提示：

1 <= N <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/divisor-game
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 */
#include <vector>
using std::vector;

class divisor_game
{

public:
    bool divisorGame(int N)
    {
        vector<bool> status(N + 1, false);
        status[2] = true;
        for (int i = 3; i <= N; i++)
        {
            for (int j = 1; j < i; ++j)
            {
                if (i % j != 0)
                {
                    continue;
                }
                if (!status[i - j])
                {
                    status[i] = true;
                    break;
                }
            }
        }

        return status[N];
    }
};

// dp,我疯狂的dp.
// Wed,March3,2021
// 16:09:58:418:637503845984188639

#pragma region REFERENCE
#define REFERENCE
#ifndef REFERENCE

/* 方法一：数学
思路与算法

博弈类的问题常常让我们摸不着头脑。当我们没有解题思路的时候，不妨试着写几项试试：

N = 1 的时候，区间 (0, 1)(0,1) 中没有整数是 nn 的因数，所以此时 Alice 败。
N = 2 的时候，Alice 只能拿 11，NN 变成 11，\text{Bob}Bob 无法继续操作，故 Alice 胜。
N = 3 的时候，Alice 只能拿 11，NN 变成 22，根据 N = 2N=2 的结论，我们知道此时 \text{Bob}Bob 会获胜，Alice 败。
N = 4 的时候，Alice 能拿 11 或 22，如果 Alice 拿 11，根据 N = 3N=3 的结论，\text{Bob}Bob 会失败，Alice 会获胜。
N = 5 的时候，Alice 只能拿 11，根据 N = 4N=4 的结论，Alice 会失败。
......
写到这里，也许你有了一些猜想。没关系，请大胆地猜想，在这种情况下大胆地猜想是 AC 的第一步。也许你会发现这样一个现象：NN 为奇数的时候 Alice（先手）必败，NN 为偶数的时候 Alice 必胜。 这个猜想是否正确呢？下面我们来想办法证明它。

证明

N = 1N=1 和 N = 2N=2 时结论成立。

N > 2N>2 时，假设 N \leq kN≤k 时该结论成立，则 N = k + 1N=k+1 时：

如果 kk 为偶数，则 k + 1k+1 为奇数，xx 是 k + 1k+1 的因数，只可能是奇数，而奇数减去奇数等于偶数，且 k + 1 - x \leq kk+1−x≤k，故轮到 \text{Bob}Bob 的时候都是偶数。而根据我们的猜想假设 N\le kN≤k 的时候偶数的时候先手必胜，故此时无论 Alice 拿走什么，\text{Bob}Bob 都会处于必胜态，所以 Alice 处于必败态。
如果 kk 为奇数，则 k + 1k+1 为偶数，xx 可以是奇数也可以是偶数，若 Alice 减去一个奇数，那么 k + 1 - xk+1−x 是一个小于等于 kk 的奇数，此时 \text{Bob}Bob 占有它，处于必败态，则 Alice 处于必胜态。
综上所述，这个猜想是正确的。

下面是代码实现。 */

class Solution
{
public:
    bool divisorGame(int N)
    {
        return N % 2 == 0;
    }
};
/* 复杂度分析

时间复杂度：O(1)O(1)。
空间复杂度：O(1)O(1)。 */

/* 方法二：动态规划
思路与算法

在「方法一」中，我们写出了前面几项的答案，在这个过程中我们发现，Alice 处在 N = kN=k 的状态时，他（她）做一步操作，必然使得 \text{Bob}Bob 处于 N = m (m < k)N=m(m<k) 的状态。因此我们只要看是否存在一个 mm 是必败的状态，那么 Alice 直接执行对应的操作让当前的数字变成 mm，Alice 就必胜了，如果没有任何一个是必败的状态的话，说明 Alice 无论怎么进行操作，最后都会让 \text{Bob}Bob 处于必胜的状态，此时 Alice 是必败的。

结合以上我们定义 f[i]f[i] 表示当前数字 ii 的时候先手是处于必胜态还是必败态，\texttt{true}true 表示先手必胜，\texttt{false}false 表示先手必败，从前往后递推，根据我们上文的分析，枚举 ii 在 (0, i)(0,i) 中 ii 的因数 jj，看是否存在 f[i-j]f[i−j] 为必败态即可。

代码如下。 */

class Solution
{
public:
    bool divisorGame(int N)
    {
        vector<int> f(N + 5, false);

        f[1] = false;
        f[2] = true;
        for (int i = 3; i <= N; ++i)
        {
            for (int j = 1; j < i; ++j)
            {
                if (i % j == 0 && !f[i - j])
                {
                    f[i] = true;
                    break;
                }
            }
        }

        return f[N];
    }
};

/* 复杂度分析

时间复杂度：O(n^2)O(n 
2
 )。递推的时候一共有 nn 个状态要计算，每个状态需要 O(n)O(n) 的时间枚举因数，因此总时间复杂度为 O(n^2)O(n 
2
 )。
空间复杂度：O(n)O(n)。我们需要 O(n)O(n) 的空间存储递推数组 ff 的值。

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/divisor-game/solution/chu-shu-bo-yi-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。 */

#endif
#pragma endregion