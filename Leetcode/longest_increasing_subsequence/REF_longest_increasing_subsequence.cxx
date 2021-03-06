/* 

方法一：动态规划
思路与算法

定义 {dp}[i]dp[i] 为考虑前 ii 个元素，以第 ii 个数字结尾的最长上升子序列的长度，注意 {nums}[i]nums[i] 必须被选取。

我们从小到大计算 {dp}dp 数组的值，在计算 {dp}[i]dp[i] 之前，我们已经计算出 {dp}[0 \ldots i-1]dp[0…i−1] 的值，则状态转移方程为：

{dp}[i] = \max({dp}[j]) + 1, \text{其中} \, 0 \leq j < i \, \text{且} \, {num}[j]<{num}[i]
dp[i]=max(dp[j])+1,其中0≤j<i且num[j]<num[i]

即考虑往 {dp}[0 \ldots i-1]dp[0…i−1] 中最长的上升子序列后面再加一个 {nums}[i]nums[i]。由于 {dp}[j]dp[j] 代表 {nums}[0 \ldots j]nums[0…j] 中以 {nums}[j]nums[j] 结尾的最长上升子序列，所以如果能从 {dp}[j]dp[j] 这个状态转移过来，那么 {nums}[i]nums[i] 必然要大于 {nums}[j]nums[j]，才能将 {nums}[i]nums[i] 放在 {nums}[j]nums[j] 后面以形成更长的上升子序列。

最后，整个数组的最长上升子序列即所有 {dp}[i]dp[i] 中的最大值。

\text{LIS}_{{length}}= \max({dp}[i]), \text{其中} \, 0\leq i < n
LIS 
length
​	
 =max(dp[i]),其中0≤i<n



1 / 23



class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = (int)nums.size();
        if (n == 0) {
            return 0;
        }
        vector<int> dp(n, 0);
        for (int i = 0; i < n; ++i) {
            dp[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};
复杂度分析

时间复杂度：O(n^2)O(n 
2
 )，其中 nn 为数组 {nums}nums 的长度。动态规划的状态数为 nn，计算状态 dp[i]dp[i] 时，需要 O(n)O(n) 的时间遍历 dp[0 \ldots i-1]dp[0…i−1] 的所有状态，所以总时间复杂度为 O(n^2)O(n 
2
 )。

空间复杂度：O(n)O(n)，需要额外使用长度为 nn 的 dpdp 数组。

方法二：贪心 + 二分查找
思路与算法

考虑一个简单的贪心，如果我们要使上升子序列尽可能的长，则我们需要让序列上升得尽可能慢，因此我们希望每次在上升子序列最后加上的那个数尽可能的小。

基于上面的贪心思路，我们维护一个数组 d[i] ，表示长度为 i 的最长上升子序列的末尾元素的最小值，用 len 记录目前最长上升子序列的长度，起始时 len 为 1，d[1] = {nums}[0]d[1]=nums[0]。

同时我们可以注意到 d[i]d[i] 是关于 ii 单调递增的。因为如果 d[j] \geq d[i]d[j]≥d[i] 且 j < ij<i，我们考虑从长度为 ii 的最长上升子序列的末尾删除 i-ji−j 个元素，那么这个序列长度变为 jj ，且第 jj 个元素 xx（末尾元素）必然小于 d[i]d[i]，也就小于 d[j]d[j]。那么我们就找到了一个长度为 jj 的最长上升子序列，并且末尾元素比 d[j]d[j] 小，从而产生了矛盾。因此数组 dd 的单调性得证。

我们依次遍历数组 {nums}nums 中的每个元素，并更新数组 dd 和 lenlen 的值。如果 {nums}[i] > d[{len}]nums[i]>d[len] 则更新 len = len + 1len=len+1，否则在 d[1 \ldots len]d[1…len]中找满足 d[i - 1] < {nums}[j] < d[i]d[i−1]<nums[j]<d[i] 的下标 ii，并更新 d[i] = {nums}[j]d[i]=nums[j]。

根据 dd 数组的单调性，我们可以使用二分查找寻找下标 ii，优化时间复杂度。

最后整个算法流程为：

设当前已求出的最长上升子序列的长度为 {len}len（初始时为 11），从前往后遍历数组 {nums}nums，在遍历到 {nums}[i]nums[i] 时：

如果 {nums}[i] > d[{len}]nums[i]>d[len] ，则直接加入到 dd 数组末尾，并更新 {len} = {len} + 1len=len+1；

否则，在 dd 数组中二分查找，找到第一个比 {nums}[i]nums[i] 小的数 d[k]d[k] ，并更新 d[k + 1] = {nums}[i]d[k+1]=nums[i]。

以输入序列 [0, 8, 4, 12, 2][0,8,4,12,2] 为例：

第一步插入 00，d = [0]d=[0]；

第二步插入 88，d = [0, 8]d=[0,8]；

第三步插入 44，d = [0, 4]d=[0,4]；

第四步插入 1212，d = [0, 4, 12]d=[0,4,12]；

第五步插入 22，d = [0, 2, 12]d=[0,2,12]。

最终得到最大递增子序列长度为 33。

JavaC++Python3

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = 1, n = (int)nums.size();
        if (n == 0) {
            return 0;
        }
        vector<int> d(n + 1, 0);
        d[len] = nums[0];
        for (int i = 1; i < n; ++i) {
            if (nums[i] > d[len]) {
                d[++len] = nums[i];
            } else {
                int l = 1, r = len, pos = 0; // 如果找不到说明所有的数都比 nums[i] 大，此时要更新 d[1]，所以这里将 pos 设为 0
                while (l <= r) {
                    int mid = (l + r) >> 1;
                    if (d[mid] < nums[i]) {
                        pos = mid;
                        l = mid + 1;
                    } else {
                        r = mid - 1;
                    }
                }
                d[pos + 1] = nums[i];
            }
        }
        return len;
    }
};
复杂度分析

时间复杂度：O(n\log n)O(nlogn)。数组 {nums}nums 的长度为 nn，我们依次用数组中的元素去更新 dd 数组，而更新 dd 数组时需要进行 O(\log n)O(logn) 的二分搜索，所以总时间复杂度为 O(n\log n)O(nlogn)。

空间复杂度：O(n)O(n)，需要额外使用长度为 nn 的 dd 数组。

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/longest-increasing-subsequence/solution/zui-chang-shang-sheng-zi-xu-lie-by-leetcode-soluti/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

 */

// basic.
// c/c++/c#
// f#
// go
// haskell
// java javascript
// kotiln
// lua
// python
// rust/ruby
// swift
// typescript
// zext.