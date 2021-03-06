/* 

方法一：前缀和
最朴素的想法是存储数组 \textit{nums}nums 的值，每次调用 \text{sumRange}sumRange 时，通过循环的方法计算数组 \textit{nums}nums 从下标 ii 到下标 jj 范围内的元素和，需要计算 j-i+1j−i+1 个元素的和。由于每次检索的时间和检索的下标范围有关，因此检索的时间复杂度较高，如果检索次数较多，则会超出时间限制。

由于会进行多次检索，即多次调用 \text{sumRange}sumRange，因此为了降低检索的总时间，应该降低 \text{sumRange}sumRange 的时间复杂度，最理想的情况是时间复杂度 O(1)O(1)。为了将检索的时间复杂度降到 O(1)O(1)，需要在初始化的时候进行预处理。

注意到当 i \le ji≤j 时，\text{sumRange}(i,j)sumRange(i,j) 可以写成如下形式：

\begin{aligned} &\quad \ \text{sumRange}(i,j) \\ &=\sum\limits_{k=i}^j \textit{nums}[k] \\ &= \sum\limits_{k=0}^j \textit{nums}[k] - \sum\limits_{k=0}^{i-1} \textit{nums}[k] \end{aligned}
​	
  
 sumRange(i,j)
= 
k=i
∑
j
​	
 nums[k]
= 
k=0
∑
j
​	
 nums[k]− 
k=0
∑
i−1
​	
 nums[k]
​	
 

由此可知，要计算 \text{sumRange}(i,j)sumRange(i,j)，则需要计算数组 \textit{nums}nums 在下标 jj 和下标 i-1i−1 的前缀和，然后计算两个前缀和的差。

如果可以在初始化的时候计算出数组 \textit{nums}nums 在每个下标处的前缀和，即可满足每次调用 \text{sumRange}sumRange 的时间复杂度都是 O(1)O(1)。

具体实现方面，假设数组 \textit{nums}nums 的长度为 nn，创建长度为 n+1n+1 的前缀和数组 \textit{sums}sums，对于 0 \le i<n0≤i<n 都有 \textit{sums}[i+1]=\textit{sums}[i]+\textit{nums}[i]sums[i+1]=sums[i]+nums[i]，则当 0<i \le n0<i≤n 时，\textit{sums}[i]sums[i] 表示数组 \textit{nums}nums 从下标 00 到下标 i-1i−1 的前缀和。

将前缀和数组 \textit{sums}sums 的长度设为 n+1n+1 的目的是为了方便计算 \text{sumRange}(i,j)sumRange(i,j)，不需要对 i=0i=0 的情况特殊处理。此时有：

\text{sumRange}(i,j)=\textit{sums}[j+1]-\textit{sums}[i]
sumRange(i,j)=sums[j+1]−sums[i]

JavaJavaScriptGolangPython3C++C

class NumArray {
    int[] sums;

    public NumArray(int[] nums) {
        int n = nums.length;
        sums = new int[n + 1];
        for (int i = 0; i < n; i++) {
            sums[i + 1] = sums[i] + nums[i];
        }
    }
    
    public int sumRange(int i, int j) {
        return sums[j + 1] - sums[i];
    }
}
复杂度分析

时间复杂度：初始化 O(n)O(n)，每次检索 O(1)O(1)，其中 nn 是数组 \textit{nums}nums 的长度。
初始化需要遍历数组 \textit{nums}nums 计算前缀和，时间复杂度是 O(n)O(n)。
每次检索只需要得到两个下标处的前缀和，然后计算差值，时间复杂度是 O(1)O(1)。

空间复杂度：O(n)O(n)，其中 nn 是数组 \textit{nums}nums 的长度。需要创建一个长度为 n+1n+1 的前缀和数组。

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/range-sum-query-immutable/solution/qu-yu-he-jian-suo-shu-zu-bu-ke-bian-by-l-px41/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

 */