/* 

给定一个由若干 0 和 1 组成的数组 A，我们最多可以将 K 个值从 0 变成 1 。

返回仅包含 1 的最长（连续）子数组的长度。

 

示例 1：

输入：A = [1,1,1,0,0,0,1,1,1,1,0], K = 2
输出：6
解释： 
[1,1,1,0,0,1,1,1,1,1,1]
粗体数字从 0 翻转到 1，最长的子数组长度为 6。
示例 2：

输入：A = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], K = 3
输出：10
解释：
[0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
粗体数字从 0 翻转到 1，最长的子数组长度为 10。
 

提示：

1 <= A.length <= 20000
0 <= K <= A.length
A[i] 为 0 或 1 
通过次数35,218提交次数58,508

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/max-consecutive-ones-iii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 */

#include <vector>
#include <iostream>
using std::cout;
using std::endl;
using std::vector;

class max_consecutive_ones_iii
{
private:
    /* data */
public:
    max_consecutive_ones_iii(/* args */);
    ~max_consecutive_ones_iii();
    int longestOnes(vector<int> &A, int K)
    {

        auto front = A.begin();
        auto back = A.begin();
        int count = 0;
        int ans = 0;
        while (back != A.end())
        {
            count = *back ? count : count + 1;
            while (count > K)
            {
                if (!*(front++))
                    --count;
            }
            ++back;
            ans = (back - front) > ans ? back - front : ans;
        }
        return ans;
    }
};

max_consecutive_ones_iii::max_consecutive_ones_iii(/* args */)
{
}

max_consecutive_ones_iii::~max_consecutive_ones_iii()
{
}

int main()
{

    vector<int> ivec{1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    max_consecutive_ones_iii mcoiii;
    cout << mcoiii.longestOnes(ivec, 2) << "\n";
}

// 参考了一下别人的思想.
// Sat,Feb20,2021
// 10:45:43:93:637494147430938851
