/* 

爱丽丝和鲍勃有不同大小的糖果棒：A[i] 是爱丽丝拥有的第 i 根糖果棒的大小，B[j] 是鲍勃拥有的第 j 根糖果棒的大小。

因为他们是朋友，所以他们想交换一根糖果棒，这样交换后，他们都有相同的糖果总量。（一个人拥有的糖果总量是他们拥有的糖果棒大小的总和。）

返回一个整数数组 ans，其中 ans[0] 是爱丽丝必须交换的糖果棒的大小，ans[1] 是 Bob 必须交换的糖果棒的大小。

如果有多个答案，你可以返回其中任何一个。保证答案存在。

 

示例 1：

输入：A = [1,1], B = [2,2]
输出：[1,2]
示例 2：

输入：A = [1,2], B = [2,3]
输出：[1,2]
示例 3：

输入：A = [2], B = [1,3]
输出：[2,3]
示例 4：

输入：A = [1,2,5], B = [2,4]
输出：[5,4]
 

提示：

1 <= A.length <= 10000
1 <= B.length <= 10000
1 <= A[i] <= 100000
1 <= B[i] <= 100000
保证爱丽丝与鲍勃的糖果总量不同。
答案肯定存在。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/fair-candy-swap
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 */

#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_set>
using std::accumulate;
using std::sort;
using std::unordered_set;
using std::vector;
class fair_candy_swap
{
private:
    /* data */
public:
    fair_candy_swap(/* args */);
    ~fair_candy_swap();
    vector<int> fairCandySwap(vector<int> &A, vector<int> &B)
    {

        int A_sum = accumulate(begin(A), end(A), 0);
        int B_sum = accumulate(begin(B), end(B), 0);
        int dif = (B_sum - A_sum) / 2;

        /* 
        
        Unordered set is an associative container that contains a set of unique objects of type Key. 
        Search, insertion, and removal have average constant-time complexity.

        Internally, the elements are not sorted in any particular order, but organized into buckets. 
        Which bucket an element is placed into depends entirely on the hash of its value. 
        This allows fast access to individual elements, since once a hash is computed, 
        it refers to the exact bucket the element is placed into.

         */

        unordered_set<int> Bset(B.begin(), B.end());
        for (int i = 0; i < A.size(); i++)
        {
            if (Bset.count(A[i] + dif))
                return {A[i], A[i] + dif};
        }
        return {-1, -1};
    }
};

fair_candy_swap::fair_candy_swap(/* args */)
{
}

fair_candy_swap::~fair_candy_swap()
{
}

//      result={x,y}
//      y - x = ( sum_b - sum_a ) / 2;
//          y = x + ( sum_b - sum_a ) / 2;

/* 

        int A_sum = accumulate(begin(A), end(A), 0);
        int B_sum = accumulate(begin(B), end(B), 0);
        int dif = (B_sum - A_sum) / 2;
        unordered_set<int> Bset(B.begin(), B.end());
        for (int i = 0; i < A.size(); i++) {
            if (Bset.count(A[i] + dif)) return {A[i], A[i] + dif};
        }
        return {-1, -1};

 */

// 这个问题好像没有别的解决思路，不同解法的主要区别在于寻找y的方式,
// 最容易想到并实现的使用二重循环寻找的方法拥有O(n^2)的时间复杂度
// 或者，可以使用二分法寻找 y,时间复杂度大概为O(n)
// 或者，使用哈希表寻找，拥有常数级别的时间复杂度.

// Mon,Feb1,2021