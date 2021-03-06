/* 

给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的每个数字在每个组合中只能使用一次。

说明：

所有数字（包括目标数）都是正整数。
解集不能包含重复的组合。 
示例 1:

输入: candidates = [10,1,2,7,6,1,5], target = 8,
所求解集为:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
示例 2:

输入: candidates = [2,5,2,1,2], target = 5,
所求解集为:
[
  [1,2,2],
  [5]
]
通过次数133,110提交次数207,784

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/combination-sum-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 */

#include <algorithm>
#include <vector>
using std::sort;
using std::vector;

class combination_sum_ii
{
private:
    /* data */
public:
    combination_sum_ii(/* args */);
    ~combination_sum_ii();
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        [[不会]]
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        auto front_dector = candidates.begin();
        auto back_dector = candidates.end();
        while (front_dector < back_dector)
        {
            int temp_sum = *front_dector + *back_dector;
            if(temp_sum==target)
            {

            }
        }
    }
};

combination_sum_ii::combination_sum_ii(/* args */)
{
}

combination_sum_ii::~combination_sum_ii()
{
}

/* 

方法一：回溯
思路与算法

由于我们需要求出所有和为 \textit{target}target 的组合，并且每个数只能使用一次，因此我们可以使用递归 + 回溯的方法来解决这个问题：

我们用 \text{dfs}(\textit{pos}, \textit{rest})dfs(pos,rest) 表示递归的函数，其中 \textit{pos}pos 表示我们当前递归到了数组 \textit{candidates}candidates 中的第 \textit{pos}pos 个数，而 \textit{rest}rest 表示我们还需要选择和为 \textit{rest}rest 的数放入列表作为一个组合；

对于当前的第 \textit{pos}pos 个数，我们有两种方法：选或者不选。如果我们选了这个数，那么我们调用 \text{dfs}(\textit{pos}+1, \textit{rest} - \textit{candidates}[\textit{pos}])dfs(pos+1,rest−candidates[pos]) 进行递归，注意这里必须满足 \textit{rest} \geq \textit{candidates}[\textit{pos}]rest≥candidates[pos]。如果我们不选这个数，那么我们调用 \text{dfs}(\textit{pos}+1, \textit{rest})dfs(pos+1,rest) 进行递归；

在某次递归开始前，如果 \textit{rest}rest 的值为 00，说明我们找到了一个和为 \textit{target}target 的组合，将其放入答案中。每次调用递归函数前，如果我们选了那个数，就需要将其放入列表的末尾，该列表中存储了我们选的所有数。在回溯时，如果我们选了那个数，就要将其从列表的末尾删除。

上述算法就是一个标准的递归 + 回溯算法，但是它并不适用于本题。这是因为题目描述中规定了解集不能包含重复的组合，而上述的算法中并没有去除重复的组合。

例如当 \textit{candidates} = [2, 2]candidates=[2,2]，\textit{target} = 2target=2 时，上述算法会将列表 [2][2] 放入答案两次。

因此，我们需要改进上述算法，在求出组合的过程中就进行去重的操作。我们可以考虑将相同的数放在一起进行处理，也就是说，如果数 \textit{x}x 出现了 yy 次，那么在递归时一次性地处理它们，即分别调用选择 0, 1, \cdots, y0,1,⋯,y 次 xx 的递归函数。这样我们就不会得到重复的组合。具体地：

我们使用一个哈希映射（HashMap）统计数组 \textit{candidates}candidates 中每个数出现的次数。在统计完成之后，我们将结果放入一个列表 \textit{freq}freq 中，方便后续的递归使用。

列表 \textit{freq}freq 的长度即为数组 \textit{candidates}candidates 中不同数的个数。其中的每一项对应着哈希映射中的一个键值对，即某个数以及它出现的次数。
在递归时，对于当前的第 \textit{pos}pos 个数，它的值为 \textit{freq}[\textit{pos}][0]freq[pos][0]，出现的次数为 \textit{freq}[\textit{pos}][1]freq[pos][1]，那么我们可以调用

\text{dfs}(\textit{pos}+1, \textit{rest} - i \times \textit{freq}[\textit{pos}][0])
dfs(pos+1,rest−i×freq[pos][0])

即我们选择了这个数 ii 次。这里 ii 不能大于这个数出现的次数，并且 i \times \textit{freq}[\textit{pos}][0]i×freq[pos][0] 也不能大于 \textit{rest}rest。同时，我们需要将 ii 个 \textit{freq}[\textit{pos}][0]freq[pos][0] 放入列表中。

这样一来，我们就可以不重复地枚举所有的组合了。

我们还可以进行什么优化（剪枝）呢？一种比较常用的优化方法是，我们将 \textit{freq}freq 根据数从小到大排序，这样我们在递归时会先选择小的数，再选择大的数。这样做的好处是，当我们递归到 \text{dfs}(\textit{pos}, \textit{rest})dfs(pos,rest) 时，如果 \textit{freq}[\textit{pos}][0]freq[pos][0] 已经大于 \textit{rest}rest，那么后面还没有递归到的数也都大于 \textit{rest}rest，这就说明不可能再选择若干个和为 \textit{rest}rest 的数放入列表了。此时，我们就可以直接回溯。

代码
class Solution {
private:
    vector<pair<int, int>> freq;
    vector<vector<int>> ans;
    vector<int> sequence;

public:
    void dfs(int pos, int rest) {
        if (rest == 0) {
            ans.push_back(sequence);
            return;
        }
        if (pos == freq.size() || rest < freq[pos].first) {
            return;
        }

        dfs(pos + 1, rest);

        int most = min(rest / freq[pos].first, freq[pos].second);
        for (int i = 1; i <= most; ++i) {
            sequence.push_back(freq[pos].first);
            dfs(pos + 1, rest - i * freq[pos].first);
        }
        for (int i = 1; i <= most; ++i) {
            sequence.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        for (int num: candidates) {
            if (freq.empty() || num != freq.back().first) {
                freq.emplace_back(num, 1);
            } else {
                ++freq.back().second;
            }
        }
        dfs(0, target);
        return ans;
    }
};
复杂度分析

时间复杂度：O(2^n \times n)O(2 
n
 ×n)，其中 nn 是数组 \textit{candidates}candidates 的长度。在大部分递归 + 回溯的题目中，我们无法给出一个严格的渐进紧界，故这里只分析一个较为宽松的渐进上界。在最坏的情况下，数组中的每个数都不相同，那么列表 \textit{freq}freq 的长度同样为 nn。在递归时，每个位置可以选或不选，如果数组中所有数的和不超过 \textit{target}target，那么 2^n2 
n
  种组合都会被枚举到；在 \textit{target}target 小于数组中所有数的和时，我们并不能解析地算出满足题目要求的组合的数量，但我们知道每得到一个满足要求的组合，需要 O(n)O(n) 的时间将其放入答案中，因此我们将 O(2^n)O(2 
n
 ) 与 O(n)O(n) 相乘，即可估算出一个宽松的时间复杂度上界。

由于 O(2^n \times n)O(2 
n
 ×n) 在渐进意义下大于排序的时间复杂度 O(n \log n)O(nlogn)，因此后者可以忽略不计。
空间复杂度：O(n)O(n)。除了存储答案的数组外，我们需要 O(n)O(n) 的空间存储列表 \textit{freq}freq、递归中存储当前选择的数的列表、以及递归需要的栈。

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/combination-sum-ii/solution/zu-he-zong-he-ii-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

 */

// Wed,Feb24,2021
