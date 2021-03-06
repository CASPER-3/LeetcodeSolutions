/* 

魔术索引。 在数组A[0...n-1]中，有所谓的魔术索引，满足条件A[i] = i。给定一个有序整数数组，编写一种方法找出魔术索引，若有的话，在数组A中找出一个魔术索引，如果没有，则返回-1。若有多个魔术索引，返回索引值最小的一个。

示例1:

 输入：nums = [0, 2, 3, 4, 5]
 输出：0
 说明: 0下标的元素为0
示例2:

 输入：nums = [1, 1, 1]
 输出：1
说明:

nums长度在[1, 1000000]之间
此题为原书中的 Follow-up，即数组中可能包含重复元素的版本
通过次数45,430提交次数66,681

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/magic-index-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 */

#include <vector>
#include <iostream>
using std::cout;
using std::endl;
using std::vector;

class magic_index_lcci
{
private:
    /* data */
public:
    magic_index_lcci(/* args */);
    ~magic_index_lcci();
    int findMagicIndex(vector<int> &nums)
    {
        int left = 0;
        int right = nums.size() - 1;
        int mid = 0;
        while (left <= right)
        {
            mid = left + ((right - left) >> 1);
            if (nums[mid] == mid)
            {
                return mid;
            }
            if (nums[mid] > mid)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return -1;
    }
};

magic_index_lcci::magic_index_lcci(/* args */)
{
}

magic_index_lcci::~magic_index_lcci()
{
}

int main()
{
    vector<int> ivec{1,1,1};
    magic_index_lcci mil;
    cout << mil.findMagicIndex(ivec) << endl;
}
