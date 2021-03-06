/* 
307. 区域和检索 - 数组可修改

Difficulty: medium


给你一个数组 nums ，请你完成两类查询，其中一类查询要求更新数组下标对应的值，另一类查询要求返回数组中某个范围内元素的总和。

实现 NumArray 类：

NumArray(int[] nums) 用整数数组 nums 初始化对象
void update(int index, int val) 将 nums[index] 的值更新为 val
int sumRange(int left, int right) 返回子数组 nums[left, right] 的总和（即，nums[left] + nums[left + 1], ..., nums[right]）
 

示例：

输入：
["NumArray", "sumRange", "update", "sumRange"]
[[[1, 3, 5]], [0, 2], [1, 2], [0, 2]]
输出：
[null, 9, null, 8]

解释：
NumArray numArray = new NumArray([1, 3, 5]);
numArray.sumRange(0, 2); // 返回 9 ，sum([1,3,5]) = 9
numArray.update(1, 2);   // nums = [1,2,5]
numArray.sumRange(0, 2); // 返回 8 ，sum([1,2,5]) = 9
 

提示：

1 <= nums.length <= 3 * 104
-100 <= nums[i] <= 100
0 <= index < nums.length
-100 <= val <= 100
0 <= left <= right < nums.length
最多调用 3 * 104 次 update 和 sumRange 方法
通过次数17,828提交次数31,148

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/range-sum-query-mutable
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 */

#include <vector>
#include <utility>
using std::vector;
class NumArray
{

private:
    vector<int> ivec;
    vector<int> sum;

public:
    NumArray(vector<int> &nums)
    {
        ivec = std::move(nums);
        sum.push_back(ivec[0]);
        for (int i = 1; i < ivec.size(); ++i)
        {
            sum.push_back(sum[i - 1] + ivec[i]);
        }
    }

    void update(int index, int val)
    {
        int diff = val - ivec[index];
        ivec[index] = val;
        for (int i = index; i < sum.size(); ++i)
        {
            sum[i] += diff;
        }
    }

    int sumRange(int left, int right)
    {
        return left == 0 ? sum[right] : sum[right] - sum[left - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */


/* 

线段树是一种非常灵活的数据结构，它可以用于解决多种范围查询问题，比如在对数时间内从数组中找到最小值、最大值、总和、最大公约数、最小公倍数等。



数组 A[0,1,\ldots,n-1]A[0,1,…,n−1] 的线段树是一个二叉树，其中每个节点都包含数组的一个子范围 [i\ldots j][i…j] 上的聚合信息（最小值、最大值、总和等），其左、右子节点分别包含范围 [i \ldots \frac{i+j}{2}][i… 
2
i+j
​	
 ] 和 [\frac{i + j}{2} + 1, j][ 
2
i+j
​	
 +1,j] 上的信息。

线段树既可以用数组也可以用树来实现。对于数组实现，如果索引 ii 处的元素不是一个叶节点，那么其左子节点和右子节点分别存储在索引为 2i2i 和 2i+12i+1 的元素处。

在上图所给出的示例中，每个叶节点都包含初始的数组元素 {2,4,5,7,8,9}。内部节点包含范围内相应元素的总和 - (11) 是从索引 0 到索引 2 的元素之和。而根节点 (35) 是它的两个子节点 (6) 和 (29) 的和,也是整个数组的和。

线段树可以分为以下三个步骤：

从给定数组构建线段树的预处理步骤。
修改元素时更新线段树。
使用线段树进行区域和检索。
构建线段树 :
我们将使用一种非常有效的自下而上的方法来构建线段树。从上面我们已经知道，如果某个节点 pp 包含范围 [i\ldots j][i…j] 的和，那么其左、右子节点分别包含范围 [i \ldots \frac{i + j}{2}][i… 
2
i+j
​	
 ] 和 [\frac{i + j}{2} + 1, j][ 
2
i+j
​	
 +1,j] 上的和。

因此，为了找到节点 pp 的和，我们需要提前计算其左、右子节点的和。

我们从叶节点开始，用输入数组的元素 a[0,1,\ldots,n-1]a[0,1,…,n−1] 初始化它们。然后我们逐步向上移动到更高一层来计算父节点的和，直到最后到达线段树的根节点。

作者：LeetCode
链接：https://leetcode-cn.com/problems/range-sum-query-mutable/solution/qu-yu-he-jian-suo-shu-zu-ke-xiu-gai-by-leetcode/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

 */


#include <vector>
#include <numeric>
#include <utility>
using std::vector;
using std::partial_sum;
class NumArray
{

private:
    vector<int> ivec;
    vector<int> sum;

public:
    NumArray(vector<int> &nums)
    {
        ivec = std::move(nums);
        sum.push_back(ivec[0]);
        for (int i = 1; i < ivec.size(); ++i)
        {
            sum.push_back(sum[i - 1] + ivec[i]);
        }
    }

    void update(int index, int val)
    {
        int diff = val - ivec[index];
        ivec[index] = val;
        for (int i = index; i < sum.size(); ++i)
        {
            sum[i] += diff;
        }
    }

    int sumRange(int left, int right)
    {
        return left == 0 ? sum[right] : sum[right] - sum[left - 1];
    }
};