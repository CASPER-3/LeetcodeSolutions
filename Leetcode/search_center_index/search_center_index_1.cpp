/*

724. 寻找数组的中心索引

给定一个整数类型的数组 nums，请编写一个能够返回数组 “中心索引” 的方法。

我们是这样定义数组 中心索引 的：数组中心索引的左侧所有元素相加的和等于右侧所有元素相加的和。

如果数组不存在中心索引，那么我们应该返回 -1。如果数组有多个中心索引，那么我们应该返回最靠近左边的那一个。

 

示例 1：

输入：  
nums = [1, 7, 3, 6, 5, 6]
输出：3
解释：
索引 3 (nums[3] = 6) 的左侧数之和 (1 + 7 + 3 = 11)，与右侧数之和 (5 + 6 = 11) 相等。
同时, 3 也是第一个符合要求的中心索引。
示例 2：

输入：
nums = [1, 2, 3]
输出：-1
解释：
数组中不存在满足此条件的中心索引。
 

说明：

nums 的长度范围为 [0, 10000]。
任何一个 nums[i] 将会是一个范围在 [-1000, 1000]的整数。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-pivot-index
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/
#include <iostream>
#include <vector>
using std::cout;
using std::vector;

class search_center_index
{
private:
    /* data */
public:
    search_center_index(/* args */);
    ~search_center_index();
    int pivotIndex(vector<int> &nums)
    {
        int pivot = -1;
        auto bg = nums.begin();
        auto ed = nums.end();
        const long sum = sumOfRange(nums.begin(), nums.end());
        while (bg != ed)
        {
            int left = sumOfRange(nums.begin(), bg);
            int right = sum - left - *bg;
            if (left == right)
            {
                return static_cast<int>(bg - nums.begin());
            }
            ++bg;
        }
        return pivot;
    }

    long sumOfRange(vector<int>::iterator begin, vector<int>::iterator end)
    {
        if (begin >= end)
        {
            return 0;
        }
        long sum = 0;
        while (begin != end)
        {
            sum += *begin;
            ++begin;
        }

        return sum;
    }
};

search_center_index::search_center_index(/* args */)
{
}

search_center_index::~search_center_index()
{
}

int main()
{
    vector<int> ivec = {1, 7, 3, 6, 5, 6};
    search_center_index sci;
    cout << sci.pivotIndex(ivec);
}

//Thu,Jan28,2021

/* 

方法一：前缀和
思路

记数组的全部元素之和为 total，当遍历到第 i 个元素时，设其左侧元素之和为 \textit{sum}sum，则其右侧元素之和为 total−nums 
i
​	
 −sum。左右侧元素相等即为 {sum}={total}-{nums}_sum=total−nums 
i
​	
 −sum，即 2\times\textit{sum}+\textit{nums}_i=\textit{total}2×sum+nums 
i
​	
 =total。

当中心索引左侧或右侧没有元素时，即为零个项相加，这在数学上称作「空和」{empty sum}。在程序设计中我们约定「空和是零」。

代码

C++JavaGolangJavaScriptC

class Solution {
public:
    int pivotIndex(vector<int> &nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (2 * sum + nums[i] == total) {
                return i;
            }
            sum += nums[i];
        }
        return -1;
    }
};
复杂度分析

时间复杂度：O(n)O(n)，其中 nn 为数组的长度。

空间复杂度：O(1)O(1)。

pony Ma
L1
13 小时前
想证明我抄代码？请提供我抄代码的实质证据。反正都是学术道德摆设委员会了。我建议以后算法工程师也不用重现论文了。反正就说我能实现多少提高率就行了，复现？复现是不可能的。重复实验在生命科学中并不一定可靠。那凭啥其余自然科学就要可以重现。欺负程序员？

class Solution(object):
    def pivotIndex(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        prefix = [0]
        sum_ = 0
        for i in range(n):
            sum_ += nums[i]
            prefix.append(sum_)
        ans = -1
        for j in range(n):
            if prefix[j] == prefix[-1]-prefix[j+1]:
                ans = j
                break
        return ans


并查集我唯唯诺诺 简单题我重拳出击

class Solution {
public:
    int pivotIndex(vector<int>& nums) 
    {
        long sum = 0;
        for (int x:nums) sum += x;
        long sum1 = 0;
        for (int i=0; i<nums.size(); ++i)
        {
            sum1 += nums[i];
            if (sum-sum1 == sum1-nums[i])
                return i;
        }
        return -1;
    }
};

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/find-pivot-index/solution/xun-zhao-shu-zu-de-zhong-xin-suo-yin-by-gzjle/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 */