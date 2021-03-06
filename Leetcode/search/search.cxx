/* 

统计一个数字在排序数组中出现的次数。

 

示例 1:

输入: nums = [5,7,7,8,8,10], target = 8
输出: 2
示例 2:

输入: nums = [5,7,7,8,8,10], target = 6
输出: 0
 

限制：

0 <= 数组长度 <= 50000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/zai-pai-xu-shu-zu-zhong-cha-zhao-shu-zi-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 */

#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class search
{
private:
    /* data */
public:
    search(/* args */);
    ~search();
    int searchRange(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] == target)
            {
                int count = 1;
                int lp = mid - 1;
                int rp = mid + 1;
                while (lp >= 0 && nums[lp] == target)
                {
                    ++count;
                    --lp;
                }
                while (rp < nums.size() && nums[rp] == target)
                {
                    ++count;
                    ++rp;
                }

                return count;
            }
            left = nums[mid] > target ? left : mid + 1;
            right = nums[mid] > target ? mid - 1 : right;
        }
        return 0;
    }
};

search::search(/* args */)
{
}

search::~search()
{
}

int main()
{
    search sr;
    vector<int> ivec{1};
    cout << sr.searchRange(ivec, 1) << endl;
}

// Thu,Feb18,2021