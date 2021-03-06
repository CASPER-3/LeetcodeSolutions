/* 

设计一个找到数据流中第 k 大元素的类（class）。注意是排序后的第 k 大元素，不是第 k 个不同的元素。

请实现 KthLargest 类：

KthLargest(int k, int[] nums) 使用整数 k 和整数流 nums 初始化对象。
int add(int val) 将 val 插入数据流 nums 后，返回当前数据流中第 k 大的元素。
 

示例：

输入：
["KthLargest", "add", "add", "add", "add", "add"]
[[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]
输出：
[null, 4, 5, 5, 8, 8]

解释：
KthLargest kthLargest = new KthLargest(3, [4, 5, 8, 2]);       2 4 5 6
kthLargest.add(3);   // return 4                               2 3 4 5 6
kthLargest.add(5);   // return 5                               2 3 4 5 5 6
kthLargest.add(10);  // return 5                               2 3 4 5 5 6 10
kthLargest.add(9);   // return 8
kthLargest.add(4);   // return 8
 

提示：
1 <= k <= 104
0 <= nums.length <= 104
-104 <= nums[i] <= 104
-104 <= val <= 104
最多调用 add 方法 104 次
题目数据保证，在查找第 k 大元素时，数组中至少有 k 个元素

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/kth-largest-element-in-a-stream
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 */

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using std::cout;
using std::endl;
using std::move;
using std::sort;
using std::vector;

class kth_largest_element_in_a_stream
{
private:
    vector<int> ivec;
    int index;

public:
    kth_largest_element_in_a_stream(int k, vector<int> &nums)
    {
        index = k;
        ivec = move(nums);
        sort(ivec.begin(), ivec.end());
    }

    int add(int val)
    {
        for (auto bg = ivec.begin(); bg != ivec.end(); ++bg)
        {
            if (*bg >= val)
            {
                ivec.insert(bg, val);
                goto ed;
            }
        }

        ivec.push_back(val);

    ed:
        return ivec[ivec.size() - index];
    }
};

int main()
{
    vector<int> ivec{4, 5, 8, 2};
    kth_largest_element_in_a_stream kleias(3, ivec);
    cout << kleias.add(3) << endl;
    cout << kleias.add(5) << endl;
    cout << kleias.add(10) << endl;
    cout << kleias.add(9) << endl;
    cout << kleias.add(4) << endl;
    return 0;
}

// Wed,Feb17,2021
